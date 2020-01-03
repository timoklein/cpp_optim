#pragma once
#include <chrono>
#include "optimizer.hpp"
#include "returnvalue.hpp"


class ConjugateGradient : public Optimizer
{
private:
    double epsilon;
public:
    ConjugateGradient(double epsilon = 0.0, size_t max_iter=1000): Optimizer(max_iter), epsilon {epsilon} {}
    ~ConjugateGradient() = default;

    /* \fn template<typename Function1, typename Function2>
            ReturnValue optimize(const Eigen::Vector2d &x_0,
                                 Function1 obj_func, Function2 grad_func)
     * -------------------------------------------------------------------
     * Conjugate Gradient algorithm by Fletcher-Reeves.
     * x_0:         Start value
     * obj_func:    Objective function returning a scalar
     * grad_func:   Gradient of the objective function returning a 2D-Vector
     */
    template<typename Function1, typename Function2>
    ReturnValue optimize(const Eigen::Vector2d &x_0,
                         Function1 obj_func, Function2 grad_func){

        size_t k {0};
        Eigen::Vector2d x {x_0};
        Eigen::Vector2d f_grad {grad_func(x_0)};
        Eigen::Vector2d d {-f_grad};

        auto start {std::chrono::high_resolution_clock::now()};
        while (f_grad.norm() > epsilon){
            double t {_line_search(x, d, obj_func, grad_func)};
            x += t*d;
            Eigen::Vector2d f_grad_new {grad_func(x)};
            d = -f_grad_new + (f_grad_new.squaredNorm()/f_grad.squaredNorm())*d;
            f_grad = f_grad_new;
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

