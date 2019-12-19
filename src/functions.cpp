#include "functions.hpp"

#include <array>
#include <cmath>
#include <vector>
#include <numeric>

namespace Functions {
    const std::array<std::array<double, 2>, 5> S {{
        {-3.30706291, -9.51361457},
        {0.72401805, -6.21446846},
        {0.70018933, -2.67522738},
        {3.78531809, -4.90713787},
        {3.22303997, 8.09547132}
    }};

    const std::array<double, 5> U {12.19150509, 7.19722565, 4.5, 6.66204255, 8.23307692};

    template<std::size_t OBS, std::size_t DIM>
    double h_value (std::vector<double> x,
                    const std::array<std::array<double, DIM>, OBS> &S,
                    const std::array<double,OBS> &U)
    {
        std::vector<double> temp;
        for (size_t i {0}; i < OBS; i++){

        }
        double val {std::accumulate(std::begin(temp), std::end(temp), 0.0)};
        return val;
    }

    template<std::size_t OBS, std::size_t DIM>
    double h_grad (std::vector<double> x,
                   const std::array<std::array<double,
                   DIM>, OBS> &S, const std::array<double,OBS> &U)
    {
        std::vector<double> temp;
        for (size_t i {0}; i < OBS; i++){

        }
        double val {std::accumulate(std::begin(temp), std::end(temp), 0.0)};
        return val;
    }

}


