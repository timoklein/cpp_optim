#pragma once
#include <eigen3/Eigen/Dense>
#include <chrono>


struct ReturnValue
{
    Eigen::VectorXd x_crit;
    double f_crit;
    size_t iterations;
};

