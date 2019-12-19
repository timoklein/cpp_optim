#include <iostream>
#include <src/functions.hpp>

int main()
{
    std::vector<std::vector<int>> v1 {
        {
            {1,2},
            {3,4}
        }
    };
    std::vector<std::vector<int>> v2 {
        {
            {1,0},
            {0,1}
        }
    };
    double s {2};
    /*
    auto result1 {Functions::scalar_mult(s, v1)};
    std::cout << "Scalar multiplication" << std::endl;
    for (const auto &e: result1)
        std::cout << e << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Dot product" << std::endl;
    double result2 {Functions::dot(v1, v2)};
    std::cout << result2 << std::endl;
    */
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Matrix multiplication" << std::endl;
    auto result3 {Functions::matmul(v1, v2)};
    for (const auto &i: result3){
        for (const auto &j: i)
            std::cout << j << std::endl;
    }
    std::cout << "-------------------------------" << std::endl;
    return 0;
}
