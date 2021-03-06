//
// Created by alex on 05.03.2021.
//

#ifndef SOLASOLVERS_JACOBI_H
#define SOLASOLVERS_JACOBI_H
#include <vector>
#include "../Sparse/CSR.h"
#include "../utils/overloads.h"
#include "../utils/consts.h"
template<typename T>
std::vector<T> JacobiSolver(const CSRMatrix<T>& A, const std::vector<T>& b) {
    using idx_t = typename CSRMatrix<T>::idx_t;
    std::vector<T> r(b.size()); //невязка
    std::vector<T> x(b.size()); //результирующий вектор
    std::vector<T> xNew(b.size()); //next  iteration vector


    T sum;
    r = A*x - b;
    while (norm2(r) > tolerance<T>) {
        //std::cout << "hi!\n";
        for (size_t i=0; i<A.H; ++i) {
            for (idx_t i=0; i<A.H; ++i) {
                sum = 0;
                for (idx_t j = A.rowSums[i]; j < A.rowSums[i+1]; ++j) {
                    if (j != A.cols[j]) {
                        sum += A.elements[j] * b[A.cols[j]];
                    } else {
                        continue;
                    }
                }
                xNew[i] = (b[i] - sum)/A(i, i);
            }
        }
        x = xNew;
        r = A*x - b;
    }
    return x;
}


#endif //SOLASOLVERS_JACOBI_H
