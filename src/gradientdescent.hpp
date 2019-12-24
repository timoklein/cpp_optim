#pragma once
#include <iostream>
#include "optimizer.hpp"
#include "returnvalue.hpp"


class GradientDescent : public Optimizer
{
private:
    double epsilon;
public:
    GradientDescent(double epsilon = 0.0): epsilon {epsilon} {}

    template<typename Function1, typename Function2>
    ReturnValue optimize(Eigen::Vector2d &x_0,
                         Function1 obj_func, Function2 grad_func){
        size_t k {0};
        Eigen::Vector2d x {x_0};
        Eigen::VectorXd f_grad {grad_func(x_0)};
        Eigen::Vector2d d {-f_grad};
        while (f_grad.norm() > epsilon){
            double t {_line_search(x, d, obj_func, grad_func)};
            x += t*d;
            f_grad = grad_func(x);
            d = -f_grad;
            k += 1;
            std::cout << "Iteration: " << k << std::endl;
        }

        ReturnValue result {x, obj_func(x), k};
        return result;
    }
    ~GradientDescent() = default;
};

