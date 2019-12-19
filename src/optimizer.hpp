#pragma once
#include <array>
#include <cmath>
#include <vector>
#include <numeric>

class Optimizer
{
private:
    double _line_search();


public:
    virtual void optimize () = 0;
    Optimizer();
    virtual ~Optimizer() = 0;
};

