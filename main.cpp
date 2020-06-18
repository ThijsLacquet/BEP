#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "Network/TCPClient.h"
#include "Network/UDP.h"
#include "Functions/FFT.h"
#include "Functions/QAM.h"
#include "complex.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "Other/Counter.h"
#include <thread>
#include <iostream>
#include <fstream>

using namespace std;

#define FFTCMND 0
#define QAM16CMND 2
#define DEQAM16CMND 3
#define OFDM1024CMND 4
#define DEOFDM1024CMND 5
#define DATASIZE 10240
#define NUMBEROFTHREADS 4

/*void readcsvs(complex<double>** input) {
    string realline;
    string imagline;
    char realline2[20];
    char imagline2[20];

    ifstream inputreal("/home/thijslaptop/Documents/MATLAB/outputreal.csv");
    ifstream inputimag("/home/thijslaptop/Documents/MATLAB/outputimag.csv");

    if (!inputreal.is_open()) {
        printf("Could not open input file \n");
    }

    if (!inputimag.is_open()) {
        printf("Could not open input file \n");
    }

    for (int i = 0; i < LINES; i++) {
        getline(inputreal, realline);
        getline(inputimag, imagline);
        strcpy(realline2, realline.c_str());
        strcpy(imagline2, imagline.c_str());

        (*input)[i] = complex<double>(stod(realline2), stod(imagline2));
    }
}*/

struct buffer{
    struct timespec beginTime;
    char command;
    int length;
    int n;
    char data[DATASIZE];
};

struct response {
    struct timespec beginTime;
    int length;
    char data[DATASIZE];
};

void printcomplex(complex<double> *input, size_t n) {
    printf("Printing %zu complex numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%f + %fj\n", input[i].real(), input[i].imag());
    }
}

void printcomplex(complex<int> *input, size_t n) {
    printf("Printing %zu complex numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d + %dj\n", input[i].real(), input[i].imag());
    }
}

void waitUntilStart(char *start) {
    time_t rawtime;
    struct tm *current_time;
    time(&rawtime);
    current_time = localtime(&rawtime);

    char hour_string[3];
    char minute_string[3];

    if (start[0] == 'n') {
        printf("The program will start now\n");
        return;
    }

    strncpy(hour_string, start, 2);
    strncpy(minute_string, &start[3], 2);
    printf("The program will start at: %s:%s\n", hour_string, minute_string);

    int hour = atoi(hour_string);
    int minute = atoi(minute_string);

    int seconds_left;
    while (hour > current_time->tm_hour || minute > current_time->tm_min) {
        seconds_left = (hour - current_time->tm_hour) * 3600 + (minute - current_time->tm_min) * 60 - current_time->tm_sec;
        printf("%d seconds left\n", seconds_left);
        sleep(1);

        time(&rawtime);
        current_time = localtime(&rawtime);
    }
    return;
}

void fft12Thread(int cpri_rate, TCPClient *myFFT12Client, bool *running, bool *complete) {
    struct buffer *buffer = (struct buffer*) malloc (sizeof(struct buffer));
    buffer->command = FFTCMND;

    Counter myCounter = Counter();
    double cpri_rate_double = cpri_rate;
    double cpri_rate_bytespersecond = cpri_rate_double / 8 * 1024 * 1024;
    double waittime_double = DATASIZE / cpri_rate_bytespersecond * 1.0e9;

    int waittime = waittime_double;

    printf("The program will do a BBU cycle every %d ns\n", waittime);

    buffer->length = DATASIZE / sizeof(complex<short>);
    buffer->n = 12; //12-point FFT

    while (*running) {
        buffer->beginTime = myCounter.getTime();
        //Fill buffer with random data
        for (int k = 0; k < buffer->length; k++) {
            //((complex<short> *) buffer->data)[k] = complex<short>(rand() % 65536, rand() % 65536);
            ((complex<short> *) buffer->data)[k] = complex<short>(3, 2);
        }

        (*myFFT12Client).sendTCP(buffer, sizeof(struct buffer)); //Send 12-point FFT

        myCounter.waitns(waittime);
    }

    free(buffer);
    printf("Terminated FFT12 thread\n");
    *complete = true;
}

void ifft2048Thread(TCPClient *myFFT12Client, TCPClient *myIFFT2048Client, bool *running, bool *complete) {
    struct response *response = (struct response*) malloc (sizeof(struct response));
    struct buffer *buffer = (struct buffer*) malloc (sizeof(struct buffer));

    buffer->length = DATASIZE / sizeof(complex<short>);
    buffer->n = -2048; //2048-point IFFT

    while (*running) {
        (*myFFT12Client).readTCP(response, sizeof(struct response)); //Receive 12-point FFT

        //Fill buffer with random data
        for (int k = 0; k < buffer->length; k++) {
            //((complex<short> *) buffer->data)[k] = complex<short>(rand() % 65536, rand() % 65536);
            ((complex<short> *) buffer->data)[k] = complex<short>(3, 2);
        }

        buffer->beginTime = response->beginTime;

        (*myIFFT2048Client).sendTCP(buffer, sizeof(struct buffer)); //Send 2048-point IFFT
    }
    free(buffer);
    printf("Terminated IFFT2048 thread\n");
    *complete = true;
}

void deQAM16Thread(TCPClient *myIFFT2048Client, TCPClient *myDeQAM16Client, bool *running, bool *complete) {
    struct response *response = (struct response*) malloc (sizeof(struct response));
    struct buffer *buffer = (struct buffer*) malloc (sizeof(struct buffer));

    buffer->length = DATASIZE / sizeof(complex<short>);
    buffer->command = DEQAM16CMND;

    while (*running) {
        (*myIFFT2048Client).readTCP(response, sizeof(struct response)); //Receive 2048-point IFFT

        //Fill buffer with random data
        for (int k = 0; k < buffer->length; k++) {
            ((complex<short> *) buffer->data)[k] = complex<short>((rand() % 6) - 3, (rand() % 6) - 3);
            ((complex<short> *) buffer->data)[k] = complex<short>(2, 2);
        }

        buffer->beginTime = response->beginTime;

        (*myDeQAM16Client).sendTCP(buffer, sizeof(struct buffer)); //Send 16-point deQAM
    }
    free(buffer);
    free(response);
    printf("Terminated deQAM16 thread\n");
    *complete = true;
}

void receiveThread(TCPClient *myDeQAM16Client, int cpri, bool *running, bool *complete) {
    struct response *response = (struct response*) malloc (sizeof(struct response));
    Counter myCounter = Counter();
    double timeTaken;
    ofstream myFile;
    char fileName[100];
    sprintf(fileName, "log_cpri-%d_datasize-%d.txt", cpri, DATASIZE);
    myFile.open(fileName);
    int timePassed = 0;

    myCounter.reset();

    while (*running) {
        (*myDeQAM16Client).readTCP(response, sizeof(struct response)); //Receive 16-point deQAM
        if (myCounter.hasPassed(1.0e9)) {
            myCounter.reset();
            timeTaken =  myCounter.compareTime(response->beginTime)  / 1000000;
            printf("Took: %f ms\n", timeTaken);
            myFile << timeTaken << "\n";
            timePassed++;
            if (timePassed > 120) {
                myFile.close();
                printf("Closed\n");
            }
        }
    }
    myFile.close();
    free(response);
    printf("Terminated deQAM16 thread\n");
    *complete = true;
}

/*
 * @param char **argv Arguments from the commandline:
 *      argv[1] is the edge server IP address
 *      argv[2] is the edge server port
 *      argv[3] is the CPRI data rate in mbit/s
 *      argv[4] is the amount of time the program is supposed to run
 *      argv[5] is the time (h:m) the program will start. If argv[5][0] == 'n', then the program will start immediately
 */
int main(int argc, char **argv) {
    /*
     * Read input arguments and setup BBU client
     */
    int n_arguments = 4;

    if (argc <= n_arguments) {
        printf("Error, you need to give at least %d arguments\n", n_arguments);
        return 1;
    }

    char *edge_ip = argv[1];
    __int16_t port = atoi(argv[2]);
    int cpri_rate = atoi(argv[3]);
    //int run_time = atoi(argv[4]);

    printf("Server ip: %s\n", edge_ip);
    printf("Server port: %d\n", port);
    printf("CPRI rate: %d mbit/s\n", cpri_rate);
    //printf("The program is going to run for: %d seconds\n", run_time);

    //waitUntilStart(argv[5]);

    /*
     * Initialize TCP clients and connect them with edge server
     */
    TCPClient myFFT12Client = TCPClient(edge_ip, port);
    myFFT12Client.tryconnect();

    TCPClient myIFFT2048Client = TCPClient(edge_ip, port + 1);
    myIFFT2048Client.tryconnect();

    TCPClient myDeQAM16Client = TCPClient(edge_ip, port + 2);
    myDeQAM16Client.tryconnect();

    /*
     * Allocated memory for threads
     */
    thread *myThreads = (thread *) malloc (sizeof(thread) * NUMBEROFTHREADS);
    char **name = (char **) malloc (sizeof(char*) * NUMBEROFTHREADS);
    bool *complete = (bool *) malloc (sizeof(bool) * NUMBEROFTHREADS);
    bool running = true;

    /*
     * Start threads
     */
    for (int i = 0; i < NUMBEROFTHREADS; i++) {
        //Allocate and initialize memory for specific thread
        name[i] = (char *) malloc(sizeof(char) * 25);
        complete[i] = false;
    }

    /*
     * Create threads
     */
    sprintf(name[0], "BBU_FFT12");
    myThreads[0] = thread(fft12Thread, cpri_rate, &myFFT12Client, &running, &complete[0]);

    sprintf(name[1], "BBU_IFFT2048");
    myThreads[1] = thread(ifft2048Thread, &myFFT12Client, &myIFFT2048Client, &running, &complete[1]);

    sprintf(name[2], "BBU_DeQAM16");
    myThreads[2] = thread(deQAM16Thread, &myIFFT2048Client, &myDeQAM16Client, &running, &complete[2]);

    sprintf(name[3], "BBU_receive");
    myThreads[3] = thread(receiveThread, &myDeQAM16Client, cpri_rate, &running, &complete[3]);

    /*
     * Set name of threads
     */
    for (int i = 0; i < NUMBEROFTHREADS; i++) {
        pthread_setname_np(myThreads[i].native_handle(), name[i]);
    }

    char input[100];

    while (running) {
        scanf("%s", input);
        if (strcmp(input, "stop\n")) {
            printf("Stopping\n");
            running = false;
            sleep(1);
        }
    }

    /*
     * Wait till are threads are stopped
     */
    for (int i = 0; i < NUMBEROFTHREADS; i++) {
        if (complete[i] == false) { //Reset counter if thread did not stop
            i = 0;
        } else  if (i == NUMBEROFTHREADS) { //All threads are stopped
            break;
        }
    }

    /*
     * Free memory
     */
    for (int i = 0; i < NUMBEROFTHREADS; i++) {
        free(name[i]);
    }
    free(name);
    free(myThreads);
    free(complete);
}