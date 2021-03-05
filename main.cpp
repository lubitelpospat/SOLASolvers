#include <iostream>
#include "Dense/DenseMatrix.h"
#include "Dense/GaussMethod.h"
#include "utils/consts.h"
#include "utils/overloads.h"
#include "Dense/BackSubstitution.h"
#include "Dense/LU.h"
#include "tests/testGauss.h"
#include "tests/testLU.h"
#include "tests/testLUSolver.h"
int main() {
    using T = double;
    //using idx_t = typename DenseMatrix<T>::idx_t;
    size_t minDim=3;
    size_t maxDim = 100;
    std::set<Triplet<T>> tmp_set = GenerateSquareDenseMatrix<T>(10, -100, 100);
    DenseMatrix<T> A = DenseMatrix<T>(10, 10, tmp_set);
    std::vector<T> b = GenerateVector<T>(10, -1, 1);
    std::cout << LUSolver<T>(A, b) << std::endl << GaussMethod<T>(A, b) << std::endl;
    TestLUSolver<T>(minDim, maxDim);
}
