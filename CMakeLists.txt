cmake_minimum_required(VERSION 3.17)
project(SOLASolvers)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost 1.75.0 COMPONENTS system filesystem iostreams REQUIRED)
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")

include_directories(${Boost_INCLUDE_DIRS})



add_executable(SOLASolvers main.cpp Dense/DenseMatrix.h utils/Triplet.h Dense/GaussMethod.h utils/consts.h Dense/BackSubstitution.h Generators/GenerateDenseMatrix.h utils/overloads.h tests/testGauss.h Generators/GenerateVector.h utils/gnuplot-iostream.h Dense/LU.h tests/testLU.h tests/testLUSolver.h Sparse/CSR.h Sparse/Jacobi.h Sparse/GaussSeidel.h Sparse/SimpleIteration.h Chebyshev/Chebyshev.h Sparse/SOR.h Sparse/SSOR.h)

target_link_libraries(SOLASolvers ${Boost_LIBRARIES})