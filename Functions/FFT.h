#include "Function.h"
#include <complex.h>

#ifndef BEP_EDGE_FFT_H
#define BEP_EDGE_FFT_H


class FFT {
public:
    std::complex<double>* compute_FFT(std::complex<double> *input, int n);
    std::complex<double>* compute_IFFT(std::complex<double> *input, int n);
};


#endif //BEP_EDGE_FFT_H
