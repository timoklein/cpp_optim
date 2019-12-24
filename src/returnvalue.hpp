#pragma once
#include <eigen3/Eigen/Dense>


/*
 *  struct ReturnValue
 *  Data container holding the results of an optimizer run.
 */
struct ReturnValue
{
    Eigen::VectorXd x_crit;
    double f_crit;
    size_t iterations;
    double wall_time;
};

