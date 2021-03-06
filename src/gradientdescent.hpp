#pragma once
#include <chrono>
#include "optimizer.hpp"
#include "returnvalue.hpp"

/*
 * class GradientDescent
 * Plain gradient descent optimization algorithm.
 * The Parameter epsilon determines how closely a critical point is approximated.
 */
class GradientDescent : public Optimizer
{
private:
    double epsilon;
public:
    GradientDescent(double epsilon = 0.0, size_t max_iter=1000): Optimizer(max_iter), epsilon {epsilon} {}
    ~GradientDescent() = default;

    /*
     * \fn template<typename Function1, typename Function2>
           ReturnValue optimize(Eigen::Vector2d &x_0,
                       Function1 obj_func, Function2 grad_func)
     * --------------------------------------------------------------------
     * Implementation of a basic gradient descent algorithm.
     * x_0:         This is the start value of the algorithm
     * ob_func:     Objective function. Evaluation needs to yield a scalar.
     * grad_func:   Gradient of the objective function [2D-Vector].
     */
    template<typename Function1, typename Function2>
    ReturnValue optimize(Eigen::Vector2d &x_0,
                         Function1 obj_func, Function2 grad_func){

        size_t k {0};
        Eigen::Vector2d x {x_0};
        Eigen::Vector2d f_grad {grad_func(x_0)};
        Eigen::Vector2d d {-f_grad};

        auto start {std::chrono::high_resolution_clock::now()};
        while (f_grad.norm() > epsilon){
            double t {_line_search(x, d, obj_func, grad_func)};
            x += t*d;
            f_grad = grad_func(x);
            d = -f_grad;
            if (_check_iterations(k))
                break;
            k += 1;
        }
        auto end {std::chrono::high_resolution_clock::now()};

        double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;

        ReturnValue result {x, obj_func(x), k, time_taken};
        display_result(result);
        return result;
    }
};

