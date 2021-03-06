//
// Created by alex on 05.03.2021.
//

#ifndef SOLASOLVERS_SIMPLEITERATION_H
#define SOLASOLVERS_SIMPLEITERATION_H
#include <vector>
#include "../Sparse/CSR.h"
#include "../utils/overloads.h"
#include "../utils/consts.h"

template<typename T>
std::vector<T> SimpleIterSolver(const CSRMatrix<T>& A, const std::vector<T>& b, const T& tau) {
    //Для положительно определенных, симметричных матриц
    std::vector<T> x(b.size());
    std::vector<T> r = A*x - b;

    while(norm2(r) > tolerance<T>) {
        x = x - tau*r;
        r = A*x - b;
    }
    return x;

}

#endif //SOLASOLVERS_SIMPLEITERATION_H
