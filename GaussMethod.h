//
// Created by alex on 27.02.2021.
//

#ifndef SOLASOLVERS_GAUSSMETHOD_H
#define SOLASOLVERS_GAUSSMETHOD_H
#include "DenseMatrix.h"
#include "consts.h"
#include "BackSubstitution.h"

template<typename T>
typename DenseMatrix<T>::idx_t GetFirstNonZeroElementInColumn(const DenseMatrix<T>& A, const typename DenseMatrix<T>::idx_t& columnNumber) {
    // Returns First non-zero element in a given matrix column
    using idx_t = typename DenseMatrix<T>::idx_t;
    auto sizePair = A.GetSize();
    auto W = sizePair.first;
    auto H = sizePair.second;
    if (absT(A(columnNumber, columnNumber)) > tolerance<T>) {
        //std::cout << "First handler" << std::endl;
        return columnNumber;
    } else {
        for (idx_t i=columnNumber+1; i<H; ++i) {
            if (absT(A(i, columnNumber)) > tolerance<T>) {
                return i;
            }
        }
        //std::cout << "Bad case" << std::endl;
        return columnNumber; // implement errors
    }
}

template<typename T>
std::size_t MakeTriangle(DenseMatrix<T>& A, std::vector<T>& b) { //Ax=b
    using elem_t = typename DenseMatrix<T>::elem_t;
    using idx_t = typename DenseMatrix<T>::idx_t;

    std::size_t nSwaps = 0;
    auto sizePair = A.GetSize();
    auto W = sizePair.first;
    auto H = sizePair.second;
    for (idx_t i=0; i < H-1; ++i) {
        //std::cout << "Row" << i << std::endl;
        idx_t iNonZero = GetFirstNonZeroElementInColumn(A, i);
        //std::cout << "iNonZero: " << iNonZero << std::endl;
        if (absT(A(iNonZero, i)) > tolerance<T>) {
            A.swapRows(i, iNonZero);
            std::swap(b[i], b[iNonZero]);
            nSwaps++;
        } else {
            continue; //Raise an error
        }
        for (idx_t j=i+1; j<H; ++j) {
            elem_t coef = A(j, i)/A(i,i);
            for (idx_t k=0; k<W; ++k) {
                A(j,k) -=A(i,k)*coef;
            }
            b[j] -= b[i]*coef;
        }
        //std::cout << A << std::endl;


    }
    return nSwaps;

}

template<typename T>
std::vector<T> GaussMethod(DenseMatrix<T> A, std::vector<T> b) {
    MakeTriangle(A, b);
    return SubstituteBack(A, b);
}


#endif //SOLASOLVERS_GAUSSMETHOD_H
