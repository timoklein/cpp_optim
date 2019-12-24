#pragma once
#include "optimizer.hpp"
#include "returnvalue.hpp"


class GaussNewton : public Optimizer
{
    private:
        double epsilon;
    public:
        GaussNewton(double epsilon = 0.0): epsilon {epsilon} {}
        ~GaussNewton() = default;

        template<typename Function>
        Eigen::Vector2d _get_d(const Eigen::Vector2d &x,const Eigen::Vector2d &f_grad, Function Dr){
            Eigen::Matrix2d D {Dr(x)};
            Eigen::Matrix2d A {D.transpose()*D};
            Eigen::Vector2d val {A.inverse()*f_grad};
            return val;
        }

        template<typename Function1, typename Function2, typename Function3>
        ReturnValue optimize(const Eigen::Vector2d &x_0,
                             Function1 obj_func, Function2 grad_func, Function3 Dr){
            size_t k {0};
            Eigen::Vector2d x {x_0};
            Eigen::Vector2d f_grad {grad_func(x_0)};
            Eigen::Vector2d d {_get_d<Function3>(x, f_grad, Dr)};
            while (f_grad.norm() > epsilon){
                double t {_line_search(x, d, obj_func, grad_func)};
                x += t*d;
                f_grad = grad_func(x);
                d = _get_d<Function3>(x, f_grad, Dr);
                k += 1;
            }

            ReturnValue result {x, obj_func(x), k};
            display_result(result);
            return result;
        }
};

