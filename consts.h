//
// Created by alex on 28.02.2021.
//

#ifndef SOLASOLVERS_CONSTS_H
#define SOLASOLVERS_CONSTS_H

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

#endif //SOLASOLVERS_CONSTS_H
