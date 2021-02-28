cmake_minimum_required(VERSION 3.17)
project(SOLASolvers)

set(CMAKE_CXX_STANDARD 17)

add_executable(SOLASolvers main.cpp DenseMatrix.h Triplet.h GaussMethod.h consts.h BackSubstitution.h tests/tests.h)