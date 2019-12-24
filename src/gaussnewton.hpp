#pragma once
#include <chrono>
#include "optimizer.hpp"
#include "returnvalue.hpp"


class GaussNewton : public Optimizer
{
    private:
        double epsilon;
    public:
        GaussNewton(double epsilon = 0.0): epsilon {epsilon} {}
        ~GaussNewton() = default;

        /* \fn template<typename Function>
               Eigen::Vector2d _get_d(const Eigen::Vector2d &x,const Eigen::Vector2d &f_grad, Function Dr)
         * -------------------------------------------------------------------------------------------------
         * Calculates the search direction d of the Gauss-Newton Algorithm.
         * x:           Current x vector
         * f_grad:      Gradient value at the current x vector
         * Dr:          Gradient of the linear term of a linear least squares objective function.
         */
        template<typename Function>
        Eigen::Vector2d _get_d(const Eigen::Vector2d &x,const Eigen::Vector2d &f_grad, Function Dr){
            Eigen::Matrix2d D {Dr(x)};
            Eigen::Matrix2d A {D.transpose()*D};
            Eigen::Vector2d val {- A.inverse()*f_grad};
            return val;
        }

        /* \fn template<typename Function1, typename Function2, typename Function3>
               ReturnValue optimize(const Eigen::Vector2d &x_0,
                                    Function1 obj_func, Function2 grad_func, Function3 Dr)
         * ----------------------------------------------------------------------------------
         * Implementation of the Gauss-Newton Algorithm for linear least squares problems of the form ||Ax+b||^2
         * x_0:         Start value
         * obj_func:    Objective function returning a scalar
         * grad_func:   Gradient of the objective function returning a 2D-Vector
         * Dr:          Function yielding the Jacobian matrix of the linear inner function
         */
        template<typename Function1, typename Function2, typename Function3>
        ReturnValue optimize(const Eigen::Vector2d &x_0,
                             Function1 obj_func, Function2 grad_func, Function3 Dr){

            size_t k {0};
            Eigen::Vector2d x {x_0};
            Eigen::Vector2d f_grad {grad_func(x_0)};
            Eigen::Vector2d d {_get_d<Function3>(x, f_grad, Dr)};

            auto start {std::chrono::high_resolution_clock::now()};
            while (f_grad.norm() > epsilon){
                double t {_line_search(x, d, obj_func, grad_func)};
                x += t*d;
                f_grad = grad_func(x);
                d = _get_d<Function3>(x, f_grad, Dr);
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

