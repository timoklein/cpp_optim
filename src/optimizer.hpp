#pragma once
#include <cmath>
#include <eigen3/Eigen/Dense>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <typeinfo>

#include "returnvalue.hpp"


/*
 * class Optimizer
 * This is the base class for other optimization algorithms.
 */

class Optimizer
{
protected:

    /*
     * \fn void display_result(const ReturnValue &r)
     * ---------------------------------------------
     * Displays a ResultValue object in formatted to the console.
     * */
    void display_result(const ReturnValue &r){
        std::ostringstream crit_val;
        crit_val << "["<< r.x_crit(0) << ", " << r.x_crit(1) << "]";
        std::cout << std::fixed << std::setprecision(4);


        std::cout << std::left << std::setw(20) << "Criterion"
                  << std::right << std::setw(20) << "Value" << std::endl;
        std::cout << std::setw(41) << std::setfill('-') << ' ' << std::endl;
        std::cout << std::setfill(' ');
        std::cout << std::left << std::setw(20) << "Iterations"
                  << std::right << std::setw(20) << r.iterations << std::endl;
        std::cout << std::left << std::setw(20) << "Critical point"
                  << std::right << std::setw(20) << crit_val.str() << std::endl;
        std::cout << std::left << std::setw(20) << "Function Value"
                  << std::right << std::setw(20) << r.f_crit << std::endl;
    }

    /*
     * \fn template<typename Function1, typename Function2>
        static double _line_search(const Eigen::VectorXd &x, const Eigen::VectorXd &d,
                               Function1 obj_func, Function2 grad_func,
                               double sigma = 0.2, double rho = 0.5, double gamma = 2.0)
     * ---------------------------------------------------------------------------------
     * Implements backtracking line search to determine the step size of a numerical
     * optimization algorithm.
     *  x:          Current x value of the algorithm.
     *  d:          Search direction.
     *  obj_func:   Objective function.
     *  grad_func:  Gradient of the objective function.
     *  sigma:      Parameter determining the flatness of the damped tangent.
     *  rho:        Step size decay factor.
     *  gamma:      Parameter for determining the appropriate starting step size.
     */
    template<typename Function1, typename Function2>
    static double _line_search(const Eigen::VectorXd &x, const Eigen::VectorXd &d,
                               Function1 obj_func, Function2 grad_func,
                               double sigma = 0.2, double rho = 0.5, double gamma = 2.0){
        double f_value {obj_func(x)};
        Eigen::Vector2d grad_val {grad_func(x)};
        double t {-gamma*( grad_val.dot(d) )/d.squaredNorm()};
        Eigen::Vector2d x_trial {x + t*d};
        double f_trial {obj_func(x)};
        size_t l {0};
        while (f_trial > f_value + t*sigma*grad_val.dot(d)){
            t *= rho;
            x_trial = x + t*d;
            f_trial = obj_func(x_trial);
            l += 1;
        }

        Eigen::Vector2d check {t*d};
        if (check.norm() < 1e-14)
            t = 1e-7;

        return t;
    }

};

