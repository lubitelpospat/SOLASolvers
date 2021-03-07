//
// Created by alex on 05.03.2021.
//

#ifndef SOLASOLVERS_SIMPLEITERATION_H
#define SOLASOLVERS_SIMPLEITERATION_H
#include <vector>
#include "CSR.h"
#include "../Chebyshev/Chebyshev.h"
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

template<typename T>
[[maybe_unused]] std::vector<T> FasterSimpleIterSolver(const CSRMatrix<T>& A, const std::vector<T>& b, const std::vector<T>& roots) {
    std::vector<T> x(b.size()); // начальное приближение
    std::vector<T> r = b -A*x; // невязка

    T norm = norm2(r);
    bool flag = true;
    while(flag) {
        for(auto root: roots){
            x = x - -static_cast<T>(1)/root * r;
            r = b - A*x;
            norm = norm2(x);

            if(norm < tolerance<T>) {
                flag = false;
                break;
            }
        }

    }
    return x;
}

#endif //SOLASOLVERS_SIMPLEITERATION_H
