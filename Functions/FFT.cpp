#include "FFT.h"
#include <fftw3.h>

std::complex<double>* FFT::compute_FFT(std::complex<double> *input, int n) {
    std::complex<double> *output;
    output = (std::complex<double>*) malloc(sizeof(std::complex<double>) * n);

    fftw_plan p = fftw_plan_dft_1d(n, reinterpret_cast<fftw_complex*>(input),
            reinterpret_cast<fftw_complex*>(output), FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(p);

    fftw_destroy_plan(p);

    return output;
}

std::complex<double> *FFT::compute_IFFT(std::complex<double> *input, int n) {
    std::complex<double> *output;
    output = (std::complex<double>*) malloc(sizeof(std::complex<double>) * n);

    fftw_plan p = fftw_plan_dft_1d(n, reinterpret_cast<fftw_complex*>(output),
            reinterpret_cast<fftw_complex*>(input), FFTW_BACKWARD, FFTW_ESTIMATE);

    fftw_execute(p);

    fftw_destroy_plan(p);

    return output;
}

