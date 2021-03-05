//
// Created by alex on 04.03.2021.
//

#ifndef SOLASOLVERS_OVERLOADS_H
#define SOLASOLVERS_OVERLOADS_H

#include<vector>
#include<set>
#include <iostream>
#include "../Dense/DenseMatrix.h"
#include "Triplet.h"

template <typename T>
std::vector<T> operator-(const std::vector<T>& a, const std::vector<T>& b) {
    //static_assert(a.size() == b.size(), "Vectors must have equal dimensions!");
    std::vector<T> result(a.size());
    for (size_t i=0; i<a.size(); ++i) {
        result[i] = a[i] - b[i];
    }
    return result;

}

template <typename T>
std::vector<T> operator+(const std::vector<T>& a, const std::vector<T>& b) {
    static_assert(a.size() == b.size(), "Vectors must have equal dimensions!");
    std::vector<T> result(a.size());
    for (size_t i=0; i<a.size(); ++i) {
        result[i] = a[i] + b[i];
    }
    return result;

}



template<typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
    bool flag = false;
    for (size_t i=0; i<v.size(); ++i) {
        if (flag) {
            s << " ";
        } else {
            flag = true;
        }
        s << v[i];

    }
    return s;
}



#endif //SOLASOLVERS_OVERLOADS_H
