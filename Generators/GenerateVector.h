//
// Created by alex on 04.03.2021.
//

#ifndef SOLASOLVERS_GENERATEVECTOR_H
#define SOLASOLVERS_GENERATEVECTOR_H

template <typename T>
std::vector<T> GenerateVector(const size_t& size, const int& min, const int& max) {
    srand(time(0));
    std::vector<T> result(size);
    for (size_t i=0; i<size; ++i) {
        result[i] = static_cast<T>(min + rand()%(max-min+1));
    }
    return result;
}

#endif //SOLASOLVERS_GENERATEVECTOR_H
