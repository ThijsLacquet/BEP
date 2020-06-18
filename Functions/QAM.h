#include <stdlib.h>
#include <complex.h>

using namespace std;

#ifndef BEP_EDGE_QAM_H
#define BEP_EDGE_QAM_H

/*
struct u {
    double i;
    double
    q;
};*/

class QAM {
private:
    int *i_setpoints;
    int *q_setpoints;
    int n;

public:
    QAM(int n);
    ~QAM();
    //u* compute_QAM(int q_q, int q_s, int p, std::complex<double> *z, size_t z_length);
    complex<int> *compute_QAM(int *x, size_t samples);
    int *compute_deQAM(complex<int> *x, size_t samples);
};


#endif //BEP_EDGE_QAM_H
