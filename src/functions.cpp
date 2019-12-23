#include "functions.hpp"

#include <eigen3/Eigen/Dense>
#include <cmath>
#include <iostream>

using namespace Eigen;

namespace Functions
{
    double h_val (const Eigen::Vector2d &x, const Eigen::MatrixXd &S, const Eigen::VectorXd &u){
        Eigen::VectorXd result(S.rows());
        for (int i {}; i < S.rows(); i++) {
            Eigen::Vector2d diff {x.transpose() - S.row(i)};
            result(i) = std::pow(diff.squaredNorm() - std::pow(u(i), 2), 2);
            }
        return result.sum();
    }

    Eigen::Vector2d h_grad (const Eigen::Vector2d &x, const Eigen::MatrixXd &S, const Eigen::VectorXd &u){
        Eigen::Vector2d gradient(0.0, 0.0);
        for (int i {}; i < S.rows(); i++) {
            Eigen::Vector2d diff {x.transpose() - S.row(i)};
            gradient += (diff.squaredNorm() - std::pow(u(i), 2))*diff;
            }
        return 4*gradient;
    }

    double nls_val (const Eigen::Vector2d &x){
        Eigen::Vector2d val(10*(x(1) - std::pow(x(0), 2)), 1 - x(0));
        return 0.5*val.squaredNorm();
    }

    Eigen::Vector2d nls_grad (const Eigen::Vector2d &x) {
        return Eigen::Vector2d(200*(std::pow(x(0), 3) - x(0)*x(1)) + x(0) - 1,
                               100*(x(1) - std::pow(x(0), 2)));
    }

}


