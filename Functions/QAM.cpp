#include "QAM.h"
#include <stdexcept>
#include <math.h>
#include <stdlib.h>
#include "../Functions/FFT.h"
//#include "../Other/mathextension.h"

using namespace std;

QAM::QAM(int n) {
    //Generate setpoints
    i_setpoints = (int*) malloc (sizeof(int) * n);
    q_setpoints = (int*) malloc (sizeof(int) * n);
    QAM::n = n;

    int log2n = log2(n);

    for (int i = 0; i < log2n; i++) {
        for (int q = 0; q < log2n; q++) {
            //I[n] = (i + 1 - (log2(n) / 2);
            if (q < log2n / 2) {
                q_setpoints[i * log2n + q] = -(1 - log2n + 2 * q);
            } else {
                q_setpoints[i * log2n + q] = -(-1 + log2n - ((q - 2) * 2));
            }

            if (i < log2n / 2) {
                i_setpoints[i * log2n + q] = 1 - log2n + 2 * i;
            } else {
                i_setpoints[i * log2n + q] = -1 + log2n - ((i - 2) * 2);
            }
        }
    }
}

QAM::~QAM() {
    free(i_setpoints);
    free(q_setpoints);
}

complex<int> *QAM::compute_QAM(int *x, size_t samples) {
    complex<int> *s = (complex<int> *) malloc (sizeof(complex<int>) * samples);

    complex<int> j1(0, 1);

    for (int i = 0; i < samples; i++) {
        s[i] = i_setpoints[x[i]] + q_setpoints[x[i]] * j1;
    }

    return s;
}

//Inefficient implementation. O(n) = n
int *QAM::compute_deQAM(complex<int> *x, size_t samples) {
    int *s = (int *) malloc (sizeof(int) * samples);

    for (int i = 0; i < samples; i++) {
        for (int j = 0; j < n; j++) {
            if (i_setpoints[j] == real(x[i]) && q_setpoints[j] == imag(x[i])) {
                s[i] = j;
                break;
            }
        }
    }
    return s;
}
