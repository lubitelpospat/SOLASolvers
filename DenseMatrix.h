//
// Created by alex on 27.02.2021.
//

#ifndef SOLASOLVERS_DENSEMATRIX_H
#define SOLASOLVERS_DENSEMATRIX_H

#include<vector>
#include<set>
#include<iostream>
#include "Triplet.h"

template<typename T>
class DenseMatrix{
public:
    using elem_t = T;
    using idx_t = size_t;

    std::vector<elem_t> matrix{};
private:
    idx_t W, H; // Width, Height
public:
    DenseMatrix(const idx_t &h, const idx_t &w, const std::set<Triplet<T>>& set): W(w), H(h){
        matrix.resize(W*H);
        for (auto element: set) {
            matrix[element.i*W + element.j] = element.value;
        }

    };


    elem_t& operator()(const idx_t& i, const idx_t& j) {
        return matrix[i*W + j];
    }
    const elem_t& operator()(const idx_t& i, const idx_t& j) const {
        return matrix[i*W + j];
    }

    const std::pair<idx_t, idx_t> GetSize() const {
        return std::pair<idx_t, idx_t>(W, H);
    }

    void swapRows(const idx_t& firstRow, const idx_t& secondRow) {
        for (idx_t i=0;i<W; ++i ) {
            std::swap(matrix[firstRow*W + i], matrix[secondRow*W + i]);
        }
    }

};
template<typename T>
std::ostream& operator<<(std::ostream& os, const DenseMatrix<T>& A) {
    using idx_t = typename DenseMatrix<T>::idx_t;

    auto sizePair = A.GetSize();
    auto W = sizePair.first;
    auto H = sizePair.second;
    bool flag0 = false;
    for (idx_t i=0; i<H; ++i) {
        if (flag0) {
            std::cout << std::endl;
        } else {
            flag0=true;
        }
        bool flag = false;
        for (idx_t j=0; j<W; ++j) {
            if (flag) {
                os << " ";

            } else {
                flag=true;
            }
            os << A.matrix[i*W +j];

        }


    }
    return os;
}
#endif //SOLASOLVERS_DENSEMATRIX_H
