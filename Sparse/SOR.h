//
// Created by alex on 07.03.2021.
//

#ifndef SOLASOLVERS_SOR_H
#define SOLASOLVERS_SOR_H

#include "CSR.h"
#include "../utils/overloads.h"
#include "../utils/consts.h"

template<typename T>
std::vector<T> SORSolver(const CSRMatrix<T>& A, const std::vector<T>& b, const T& omega) {
    using idx_t = typename CSRMatrix<T>::idx_t;
    std::vector<T> x(b.size());
    std::vector<T> r = b - A*x;
    std::vector<T> xOld(b.size());

    T sum;

    while (norm2(r) > tolerance<T>) {
        xOld = x;
        for (size_t i=0; i<b.size(); ++i) {
            sum = static_cast<T>(0);
            for (idx_t j = A.rowSums[i]; j < A.rowSums[i+1]; ++j) {
                if (j != A.cols[j]) {
                    sum += A.elements[j] * b[A.cols[j]];
                } else {
                    continue;
                }
            }
            x[i] = (omega*b[i] - omega *sum)/A(i, i) + (static_cast<T>(1) - omega)*xOld[i];
        }
        r = b - A*x;
    }

    return x;

}


#endif //SOLASOLVERS_SOR_H
