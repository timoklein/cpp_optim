#pragma once
#include <eigen3/Eigen/Dense>
#include <chrono>


/*
 *  struct ReturnValue
 *  Data container holding the results of an optimizer run.
 *  ------------------------------------------------------
 *  x_crit:     found minimum point of the function
 *  f_crit:     function value at the minimum point
 *  iterations: number of iterations needed to find the minimum point
 */
struct ReturnValue
{
    Eigen::VectorXd x_crit;
    double f_crit;
    size_t iterations;
};

