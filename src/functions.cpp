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

}


