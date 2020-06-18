#ifndef BEP_COUNTER_H
#define BEP_COUNTER_H

#include <time.h>

class Counter {
private:
    struct timespec spec;
    double curr_time_ns;
    double prev_time_ns;
    double curr_time_s;
    double prev_time_s;
public:
    Counter();
    void reset();
    int waitns(int waittime);
    struct timespec getTime();
    bool hasPassed(double waittime);
    double compareTime(struct timespec inputTime);
};


#endif //BEP_COUNTER_H
