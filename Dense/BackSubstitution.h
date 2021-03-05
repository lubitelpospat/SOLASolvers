//
// Created by alex on 28.02.2021.
//

#ifndef SOLASOLVERS_BACKSUBSTITUTION_H
#define SOLASOLVERS_BACKSUBSTITUTION_H
template<typename T>
std::vector<T> SubstituteBackUpperTriangular(const DenseMatrix<T>& A, const std::vector<T>& b) {
    //using idx_t = typename DenseMatrix<T>::idx_t;
    const size_t size_b = b.size();
    std::vector<T> result(size_b);
    auto sizePair = A.GetSize();
    auto W = sizePair.first;
    auto H = sizePair.second;
    result.back() = b.back()/A(H-1, W-1);
    T sum_;
    for (int i=size_b-2; i>=0; --i) {
        sum_ = 0;
        for (size_t j=i+1; j < size_b; ++j) {
            sum_ += A(i,j)*result[j];
        }
        result[i] = (b[i] - sum_)/A(i,i);
    }

    return result;
}



template<typename T>
std::vector<T> SubstituteBackLowerTriangular(const DenseMatrix<T>& A, const std::vector<T>& b) {
    //using idx_t = typename DenseMatrix<T>::idx_t;
    size_t size_b = b.size();
    std::vector<T> result(size_b);
    auto sizePair = A.GetSize();
    auto W = sizePair.first;
    auto H = sizePair.second;
    result[0] = b[0]/A(0, 0);
    T sum_;
    for (int i=1; i<A.GetSizeH(); ++i) {
        sum_ = 0;
        for (size_t j=0; j < i; ++j) {
            sum_ += A(i,j)*result[j];
        }
        result[i] = (b[i] - sum_)/A(i,i);
    }

    return result;
}



#endif //SOLASOLVERS_BACKSUBSTITUTION_H
