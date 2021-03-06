//
// Created by alex on 05.03.2021.
//

#ifndef SOLASOLVERS_CHEBYSHEV_H
#define SOLASOLVERS_CHEBYSHEV_H
#define PI 3.1415926
#include<vector>
#include<algorithm>
#include<cmath>

template<typename T>
std::vector<T> FindChebyshevRoots(const pair<T, T>& range, const size_t& pow) {

    size_t order = std::pow(2, pow);
    std::vector roots(order); //vector of roots of Chebyshev polynomial
    auto a = range.first;
    auto b = range.second;
    for (size_t i=0; i<order; ++i) {
        roots[i] = (a/2 + b/2) + (b/2-q/2)*static_cast<T>(cos(static_cast<T>(2*i+1)*M_PI_2/order));
    }
    std::vector<size_t> reorder(order);
    std::vector<size_t> idx;
    reorder.push_back(0);
    reorder.push_back(1);
    size_t currentOrder;
    for(size_t i=1; i<pow; ++i) {
        currentOrder = pow(2, i);
        reorder.resize(currentOrder);
        for (size_t j=0; j<currentOrder - 1; j+=2) {
            reorder[j] = idx[size_t(j/2)];
            reorder[j+1] = currentOrder - 1 - reorder[j];
        }
    }

    std::vector<T> result(order);
    for (size_t i=0; i < order; ++i) {
        result[i] = roots[idx[i]];
    }
    return result;


}

#endif //SOLASOLVERS_CHEBYSHEV_H
