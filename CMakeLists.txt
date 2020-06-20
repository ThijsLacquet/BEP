cmake_minimum_required(VERSION 3.15)
project(BEP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(BEP main.cpp Network/TCPServer.cpp Network/TCPServer.h Network/TCPClient.cpp Network/TCPClient.h Network/UDP.cpp Network/UDP.h Functions/FFT.cpp Functions/FFT.h Functions/QAM.cpp Functions/QAM.h Other/Counter.cpp Other/Counter.h)

target_link_libraries(BEP fftw3)