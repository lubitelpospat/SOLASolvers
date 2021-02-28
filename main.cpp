#include <iostream>
#include "DenseMatrix.h"
#include "GaussMethod.h"
#include "consts.h"
#include "BackSubstitution.h"
//#define T long long
int main() {
    using T = long double;
    using idx_t = typename DenseMatrix<T>::idx_t;
    idx_t msize = 3;
    std::set<Triplet<T>> test;
    std::vector<T> test_raw {1.0, 2.0, 3.0, 3.0, 5.0, 7.0, 1.0, 3.0, 4.0};
    for (idx_t i=0; i<msize; ++i) {
        for(idx_t j=0; j<msize; ++j) {
            test.insert({i, j, T(test_raw[i*msize+j])});
        }
    }

    DenseMatrix<T> A = DenseMatrix<T>(msize, msize, test);
    std::vector<T> b {3.0, 0.0 ,1.0};


    auto res = GaussMethod(A, b);
    std::cout << "result: " << std::endl;
    for (auto elem: res) {
        std::cout << elem << std::endl;
    }
    return 0;

}
