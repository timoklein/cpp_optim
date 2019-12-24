#pragma once
#include <cmath>
#include <iostream>
#include <eigen3/Eigen/Dense>

class Optimizer
{
protected:
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

