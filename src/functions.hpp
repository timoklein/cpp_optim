#pragma once

#include <iostream>
#include <array>
#include <cmath>
#include <vector>
#include <numeric>

namespace Functions {
    // TODO: all of these should return vectors it's possible to make things easier
    template <typename scalar, typename vector>
    vector scalar_mult(const scalar &s, const vector &v){
        vector result {v};
        for (size_t i {0}; i < result.size(); i++)
            result.at(i) *= s;
        return result;
}
    template <typename vector1, typename vector2>
    double dot (const vector1 &a, const vector2 &b){
        double result {};
        for (size_t i {0}; i < a.size(); i++)
            result += a.at(i)*b.at(i);
        return result;
    }

    // TODO: Fix this, it's wrong
    template <typename mat1, typename mat2>
    std::vector<std::vector<double>> matmul (const mat1 &a, const mat2 &b){
        size_t I {a.size()};
        size_t J {b.size()};
        size_t K {a.at(0).size()};
        std::vector<std::vector<double>> result (I, std::vector<double>(J, 0.0));
        for (size_t i {}; i < I; i++){
            for (size_t j {}; j < J; j++){
                double sum {a.at(i).at(0)*b.at(0).at(j)};
                for (size_t k {}; k < K; k++){
                    sum += a.at(i).at(k)*b.at(k).at(j);

                }
                result.at(i).at(j) = sum;
            }
        }
        return result;
    }

}

