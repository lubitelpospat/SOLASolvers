//
// Created by alex on 27.02.2021.
//

#ifndef SOLASOLVERS_TRIPLET_H
#define SOLASOLVERS_TRIPLET_H


template<typename T>
struct Triplet {
    std::size_t i;
    std::size_t j;
    T value;




};
template<typename T>
bool operator<(const Triplet<T>& lhv, const Triplet<T>& rhv) {
    return lhv.i < rhv.i || (lhv.i == rhv.i && lhv.j < rhv.j);
}

#endif //SOLASOLVERS_TRIPLET_H
