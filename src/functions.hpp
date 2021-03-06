#pragma once

#include <iostream>
#include <eigen3/Eigen/Dense>

namespace Functions
{
    // Location Problem
    double h_val (const Eigen::Vector2d &x, const Eigen::MatrixXd &s, const Eigen::VectorXd &u);
    Eigen::Vector2d h_grad (const Eigen::Vector2d &x, const Eigen::MatrixXd &S, const Eigen::VectorXd &u);

    // Rosenbrock Function
    double nls_val (const Eigen::Vector2d &x);
    Eigen::Vector2d nls_grad (const Eigen::Vector2d &x);
    Eigen::Matrix2d Dr(const Eigen::Vector2d &x);

    // Peano's function
    double p_val (const Eigen::Vector2d &x);
    Eigen::Vector2d p_grad (const Eigen::Vector2d &x);



}

