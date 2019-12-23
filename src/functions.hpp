#pragma once

#include <iostream>
#include <eigen3/Eigen/Dense>

namespace Functions
{
    double h_val (const Eigen::Vector2d &x, const Eigen::MatrixXd &s, const Eigen::VectorXd &u);
    Eigen::Vector2d h_grad (const Eigen::Vector2d &x, const Eigen::MatrixXd &S, const Eigen::VectorXd &u);
    double nls_val (const Eigen::Vector2d &x);
    Eigen::Vector2d nls_grad (const Eigen::Vector2d &x);


}

