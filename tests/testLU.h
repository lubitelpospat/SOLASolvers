//
// Created by alex on 05.03.2021.
//

#ifndef SOLASOLVERS_TESTLU_H
#define SOLASOLVERS_TESTLU_H
#include "../Generators/GenerateDenseMatrix.h"
#include "../utils/overloads.h"
#include "../Dense/DenseMatrix.h"
#include "../utils/consts.h"
#include "../utils/Triplet.h"
#include "../Dense/LU.h"
template<typename T>
void TestLU(const size_t& size) {
    std::set<Triplet<T>> tmp_set = GenerateSquareDenseMatrix<T>(size, -1000, 1000);
    DenseMatrix<T> A = DenseMatrix<T>(size, size, tmp_set);

    auto res = LU(A);
    std::cout << res.first << std::endl << res.second << std::endl;

}

#endif //SOLASOLVERS_TESTLU_H
