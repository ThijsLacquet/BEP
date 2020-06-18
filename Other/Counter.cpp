#include "Counter.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

Counter::Counter() {
    Counter::reset();
}


void Counter::reset() {
    clock_gettime(CLOCK_REALTIME, &(Counter::spec));
    Counter::curr_time_ns = difftime(round(spec.tv_nsec), 0);
    Counter::prev_time_ns = curr_time_ns;
    Counter::curr_time_s = difftime(spec.tv_sec, 0);
    Counter::prev_time_s = curr_time_s;
}

int Counter::waitns(int waittime) {
    double diff_time_ns;

    bool first = true;

    while (1) {
        clock_gettime(CLOCK_REALTIME, &(Counter::spec));
        Counter::curr_time_ns = difftime(round(Counter::spec.tv_nsec), 0);
        Counter::curr_time_s = difftime(Counter::spec.tv_sec, 0);

        diff_time_ns = Counter::curr_time_ns - Counter::prev_time_ns
                + ((Counter::curr_time_s - Counter::prev_time_s) * 1.0e9);

        if (diff_time_ns > waittime) {
            Counter::reset();
            if (first) { //Timer was already exceeded. Operation took to long.
                //printf("Operation took too long\n");
                return -1;
            } else {
                return 0;
            }
        } else {
            //usleep((waittime / 1000) / 2);
        }
        first = false;
    }
}

double Counter::compareTime(struct timespec inputTime) {
    double diff_time_ns = difftime(Counter::spec.tv_nsec, inputTime.tv_nsec);
    double diff_time_s = difftime(Counter::spec.tv_sec, inputTime.tv_sec);

    return diff_time_ns + (diff_time_s * 1.0e9);
}

struct timespec Counter::getTime() {
    return Counter::spec;
}

bool Counter::hasPassed(double waittime) {
    clock_gettime(CLOCK_REALTIME, &(Counter::spec));
    Counter::curr_time_ns = difftime(round(Counter::spec.tv_nsec), 0);
    Counter::curr_time_s = difftime(Counter::spec.tv_sec, 0);

    double diff_time_ns = Counter::curr_time_ns - Counter::prev_time_ns
                   + ((Counter::curr_time_s - Counter::prev_time_s) * 1.0e9);

    if (diff_time_ns > waittime) {
        return true;
    } else {
        return false;
    }
}