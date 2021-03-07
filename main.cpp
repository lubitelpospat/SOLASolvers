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
#include "Sparse/Jacobi.h"
#include "Sparse/GaussSeidel.h"
#include "Sparse/SimpleIteration.h"
#include "Sparse/SOR.h"
#include "Sparse/CSR.h"
#include "Sparse/SSOR.h"

int main() {
    using T = double;
    //using idx_t = typename DenseMatrix<T>::idx_t;
    //size_t minDim=3;
    //size_t maxDim = 100;
    std::set<Triplet<T>> tmp_set;
    for (size_t i=0; i<300; ++i) {
        tmp_set.insert({i, i, 1 + T(i+1)/598});

    }
    DenseMatrix<T> D = DenseMatrix<T>(300, 300, tmp_set);
    CSRMatrix<T> S = CSRMatrix<T>(300, 300, tmp_set);
    //auto tmp_set1 = GenerateSquareDenseMatrix<T>(300, -1.5, 1.5);
    //CSRMatrix<T> A = CSRMatrix<T>(300, 300, tmp_set);

    std::vector<T> b = GenerateVector<T>(300, -1, 1);
    std::cout
    << GaussMethod<T>(D, b) << std::endl
    << GaussSeidelSolver<T>(S, b) << std::endl
    << SimpleIterSolver<T>(S, b, 1) << std::endl
    << SORSolver<T>(S, b, 0.1) << std::endl
    << SSORSolver<T>(S, b, 0.1) << std::endl;
}
