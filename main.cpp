#include <iostream>
#include <iomanip>
#include <src/functions.hpp>
#include <eigen3/Eigen/Dense>

int main()
{
    // TODO: Initialize these better
    Eigen::MatrixXd S(5,2);
    S << -3.30706291, -9.51361457,
          0.72401805, -6.21446846,
          0.70018933, -2.67522738,
          3.78531809, -4.90713787,
          3.22303997, 8.09547132;
    Eigen::VectorXd u(5);
    u << 12.19150509, 7.19722565, 4.5, 6.66204255, 8.23307692;

    Eigen::Vector2d x(0.0, 0.0);

    double r1 {Functions::h_val(x, S, u)};
    std::cout << r1 << std::endl;
    Eigen::Vector2d r2 {Functions::h_grad(x, S, u)};
    std::cout << r2 << std::endl;
    return 0;
}
