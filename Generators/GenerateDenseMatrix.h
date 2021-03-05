//
// Created by alex on 04.03.2021.
//

#ifndef SOLASOLVERS_GENERATEDENSEMATRIX_H
#define SOLASOLVERS_GENERATEDENSEMATRIX_H


template<typename T>
std::set<Triplet<T>> GenerateSquareDenseMatrix(const size_t& size, const int& min, const int& max) {
    srand(time(0));
    std::set<Triplet<T>> result;
    for (size_t i=0; i<size; ++i) {
        for (size_t j=0; j<size; ++j) {
            result.insert({i, j, static_cast<T>(min + rand()%(max-min + 1))});
        }
    }
    return result;
}



#endif //SOLASOLVERS_GENERATEDENSEMATRIX_H
