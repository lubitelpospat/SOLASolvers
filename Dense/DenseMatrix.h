//
// Created by alex on 27.02.2021.
//

#ifndef SOLASOLVERS_DENSEMATRIX_H
#define SOLASOLVERS_DENSEMATRIX_H

#include<vector>
#include<set>
#include<iostream>
#include "../utils/Triplet.h"
#include "../utils/overloads.h"
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
    DenseMatrix(const idx_t &h, const idx_t &w): W(w), H(h){
        matrix.resize(W*H);

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
    [[nodiscard]] idx_t GetSizeH() const {
        return H;
    }

    [[nodiscard]] idx_t GetSizeW() const {
        return W;
    }

    void swapRows(const idx_t& firstRow, const idx_t& secondRow) {
        for (idx_t i=0;i<W; ++i ) {
            std::swap(matrix[firstRow*W + i], matrix[secondRow*W + i]);
        }
    }

};

template<typename T>
std::ostream& operator<<(std::ostream& os, const  DenseMatrix<T>& A) {
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

template<typename T>
std::vector<T> operator*(const DenseMatrix <T> &A, const std::vector<T> &b) {
    std::vector<T> result(b.size());
    for (size_t i=0; i<A.GetSizeH(); ++i) {
        T sum = 0;
        for (size_t j=0; j<A.GetSizeW(); ++j) {
            sum += A(i, j) * b[j];
        }
        result[i] = sum;

    }
    return result;
}

#endif //SOLASOLVERS_DENSEMATRIX_H
