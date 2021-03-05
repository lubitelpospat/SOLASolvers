//
// Created by alex on 04.03.2021.
//

#ifndef SOLASOLVERS_LU_H
#define SOLASOLVERS_LU_H

#include "BackSubstitution.h"
template<typename T>
std::pair<DenseMatrix<T>, DenseMatrix<T>> LU(const DenseMatrix<T>& A) {
    using idx_t = typename DenseMatrix<T>::idx_t;
    idx_t H = A.GetSizeH();
    idx_t W = A.GetSizeW();
    DenseMatrix<T> L = DenseMatrix<T>(A.GetSizeH(), A.GetSizeW());
    DenseMatrix<T> U = DenseMatrix<T>(A.GetSizeH(), A.GetSizeW());
    for (idx_t i=0; i<W; ++i) {
            L(i, i)  = 1;

    }
    T sum;
    for (idx_t i=0; i<H; ++i) {
        for (idx_t j=0; j<W; ++j) {
            sum = 0;
            if ( i <= j) {
                for (idx_t k=0; k<j; ++k) {
                    sum += L(i,k)*U(k,j);
                }
                U(i,j) = A(i,j) - sum;
            }else {
                for (idx_t k=0; k<j; ++k) {
                    sum += L(i,k)*U(k, j);
                }
                L(i,j) = (A(i,j) - sum)/U(j,j);
            }
        }
    }

    return {L, U};


}

template<typename T>
std::vector<T> LUSolver(const DenseMatrix<T>& A, const std::vector<T>& b) {
    std::pair<DenseMatrix<T>, DenseMatrix<T>> lu = LU(A);
    return SubstituteBackUpperTriangular(lu.second, SubstituteBackLowerTriangular(lu.first, b));

}
#endif //SOLASOLVERS_LU_H
