//
// Created by alex on 05.03.2021.
//

#ifndef SOLASOLVERS_TESTLUSOLVER_H
#define SOLASOLVERS_TESTLUSOLVER_H

#include <cmath>
#include "../utils/gnuplot-iostream.h"
#include "../Generators/GenerateDenseMatrix.h"
#include "../Generators/GenerateVector.h"
#include "../Dense/LU.h"
#include "../utils/overloads.h"
#include "../Dense/DenseMatrix.h"
#include "../utils/consts.h"
#include "../utils/Triplet.h"

template<typename T>
void TestLUSolver(const size_t& minDim, const size_t& maxDim) {
    std::vector<std::pair<T, T>> data;
    for (size_t i=minDim; i<maxDim; ++i) {
        //dim.push_back(static_cast<T>(i));

        std::set<Triplet<T>> tmp_set = GenerateSquareDenseMatrix<T>(i, -1000, 1000);
        DenseMatrix<T> A = DenseMatrix<T>(i, i, tmp_set);
        std::vector<T> b = GenerateVector<T>(i, -1, 1);
        std::vector<T> solution = LUSolver(A, b);
        T error_ = log(norm2(b - A*solution));
        data.emplace_back(i, error_);

    }


    Gnuplot gp;
    gp << "set xlabel 'matrix dimension'\n" << "set ylabel 'log(err)'\n" << "set grid\n";
    //gp << "set xrange [" << minDim << ":" << maxDim << "]\n"; // "set yrange [-2:2]\n";
    //gp << "plot '-' with vectors title 'pts_A'\n";
    gp << "plot '-' with lines title 'LU Decomposition Solver' lc rgb 'red'\n";
    gp.send1d(data);
    //gp << "plot [-5:5] sin(x) tit 'sin(x)'";
}

#endif //SOLASOLVERS_TESTLUSOLVER_H
