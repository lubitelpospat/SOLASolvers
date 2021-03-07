//
// Created by alex on 05.03.2021.
//

#ifndef SOLASOLVERS_CSR_H
#define SOLASOLVERS_CSR_H
#include<vector>
#include<set>
#include<algorithm>

#include "../utils/Triplet.h"
template<typename T>
class CSRMatrix {
public:
    using elm_t = T;
    using idx_t = size_t;
private:
    const idx_t H, W;
    std::vector<elm_t> elements;
    std::vector<idx_t> cols;
    std::vector<idx_t> rowSums;
    template<typename EL>
   friend std::vector<EL> JacobiSolver(const CSRMatrix<EL>& A, const std::vector<EL>& b);

    template<typename EL>
    friend std::vector<EL> GaussSeidelSolver(const CSRMatrix<EL>& A, const std::vector<EL>& b);
    template<typename EL>
    friend std::vector<EL> SORSolver(const CSRMatrix<EL>& A, const std::vector<EL>& b, const EL& omega);
    template<typename EL>
    friend std::vector<EL> SSORSolver(const CSRMatrix<EL>& A, const std::vector<EL>& b, const EL& omega);

public:
    CSRMatrix(const idx_t& H, const idx_t& W, std::set<Triplet<T>> matrix): H(H), W(W) {
        elements.resize(matrix.size());
        cols.resize(matrix.size());
        rowSums.resize(matrix.size() + 1);
        idx_t sumNonZero = 0;
        idx_t currentRow = 0;

        auto it = matrix.begin();
        for (idx_t i=0; i<matrix.size(); ++i) {
            while (currentRow < it->i) {
                rowSums[currentRow + 1] = rowSums[currentRow] + sumNonZero;
                currentRow++;
                sumNonZero=0;
            }
            elements[i] = it->value;
            sumNonZero++;
            cols[i] = it->j;
            it++;

        }
        for (++currentRow; currentRow <= H; ++currentRow) {
            rowSums[currentRow] = matrix.size();
        }

    }
    [[nodiscard]] idx_t GetSizeH() const {
        return H;

    }

    [[nodiscard]] idx_t GetSizeW() const {
        return W;

    }

    std::vector<elm_t> operator*(const std::vector<elm_t>& b) const {
        std::vector<elm_t> result(this->H);

        for (idx_t i=0; i<H; ++i) {
            for (idx_t j = rowSums[i]; j < rowSums[i+1]; ++j) {
                result[i] += elements[j]*b[cols[j]];
            }
        }
        return result;


    }
    elm_t operator()(const idx_t& i, const idx_t& j) const {
        idx_t skip = this->rowSums[i];
        idx_t count = this->rowSums[i+1] - skip;
        for (idx_t i=skip; i<this->rowSums[i+1]; ++i) {
            if (this->cols[i] == j) {
                return this->elements[i];
            }
        }
        return static_cast<elm_t>(0);


    }
};
#endif //SOLASOLVERS_CSR_H
