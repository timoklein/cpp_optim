#include <iostream>
#include <iomanip>
#include <functional>
#include <src/functions.hpp>
#include <eigen3/Eigen/Dense>

#include "src/gradientdescent.hpp"
#include <src/returnvalue.hpp>

void function_tests(const Eigen::VectorXd &x, const Eigen::MatrixXd &S, const Eigen::VectorXd &u){
    double r1 {Functions::h_val(x, S, u)};
    std::cout << r1 << std::endl;
    Eigen::Vector2d r2 {Functions::h_grad(x, S, u)};
    std::cout << r2 << std::endl;
    double r3 {Functions::nls_val(x)};
    std::cout << r3 << std::endl;
    Eigen::Vector2d r4 {Functions::nls_grad(x)};
    std::cout << r4 << std::endl;
}

int main()
{
    using namespace std::placeholders;
    Eigen::MatrixXd S(5,2);
    S << -3.30706291, -9.51361457,
          0.72401805, -6.21446846,
          0.70018933, -2.67522738,
          3.78531809, -4.90713787,
          3.22303997, 8.09547132;
    Eigen::VectorXd u(5);
    u << 12.19150509, 7.19722565, 4.5, 6.66204255, 8.23307692;

    Eigen::Vector2d x(0.0, 0.0);
    auto obj_func {std::bind(Functions::h_val, _1, S, u)};
    auto grad_func {std::bind(Functions::h_grad, _1, S, u)};


    GradientDescent gd {1e-4};
    ReturnValue res {gd.optimize(x, obj_func, grad_func)};
    std::cout << "Optimization steps: " << res.iterations << std::endl;

    return 0;
}
