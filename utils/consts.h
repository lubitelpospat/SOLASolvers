//
// Created by alex on 28.02.2021.
//

#ifndef SOLASOLVERS_CONSTS_H
#define SOLASOLVERS_CONSTS_H
#include <math.h>
template<typename T>
auto tolerance = static_cast<T>(1e-10);

template<typename T>
T absT(const T& value) {
    if (value < 0) {
        return -value;
    } else {
        return value;
    }
}

template <typename T>
T norm2(const std::vector<T>& a) {
    T result = 0;
    for (size_t i=0; i<a.size(); ++i) {
        result += a[i] * a[i];
    }
    return sqrt(result);
}

template<typename T>
T mean(const std::vector<T>& a) {
    T result = 0;
    for (size_t i=0; i<a.size(); ++i) {
        result += a[i];
    }
    return result/static_cast<T>(a.size());
}

#endif //SOLASOLVERS_CONSTS_H
