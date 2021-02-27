//
// Created by alex on 27.02.2021.
//

#ifndef SOLASOLVERS_DENSEMATRIX_H
#define SOLASOLVERS_DENSEMATRIX_H

#include<vector>
template<typename T>
class DenseMatrix{
    using elem_t T;
    using idx_t = size_t;
private:
    std::vector<elm_t> matrix;
    idx_t W, H // Width, Height
public:
    DenseMatrix(std::vector<elm_t> m, idx_t W, idx_t H): matrix(m), W(W), H(H){};
};

#endif //SOLASOLVERS_DENSEMATRIX_H
