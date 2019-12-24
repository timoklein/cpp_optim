#include <iostream>
#include <iomanip>
#include <functional>
#include <eigen3/Eigen/Dense>

#include <src/functions.hpp>
#include <src/gaussnewton.hpp>
#include "src/conjugategradient.hpp"
#include "src/gradientdescent.hpp"
#include "src/returnvalue.hpp"

void run_location(){
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

    std::cout << "Conjugate Gradient" << std::endl;
    ConjugateGradient cg {1e-4};
    ReturnValue res2 {cg.optimize(x, obj_func, grad_func)};
    std::cout << "------------------------------------------\n" << std::endl ;

    std::cout << "Gradient Descent" << std::endl;
    GradientDescent gd {1e-4};
    ReturnValue res3 {gd.optimize(x, obj_func, grad_func)};

}

void run_rosenbrock(){
    Eigen::Vector2d x(2.0, 5.0);
    std::cout << "Gauss Newton" << std::endl;
    GaussNewton gn {1e-4};
    ReturnValue res1 {gn.optimize(x, Functions::nls_val, Functions::nls_grad, Functions::Dr)};
    std::cout << "------------------------------------------\n" << std::endl ;

    std::cout << "Conjugate Gradient" << std::endl;
    ConjugateGradient cg {1e-4};
    ReturnValue res2 {cg.optimize(x, Functions::nls_val, Functions::nls_grad)};
    std::cout << "------------------------------------------\n" << std::endl ;

    std::cout << "Gradient Descent" << std::endl;
    GradientDescent gd {1e-4};
    ReturnValue res3 {gd.optimize(x, Functions::nls_val, Functions::nls_grad)};

}

int main()
{
//    run_location();

    run_rosenbrock();

    return 0;
}
