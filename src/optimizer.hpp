#pragma once
#include <array>
#include <cmath>
#include <vector>
#include <numeric>

class Optimizer
{
private:
    // TODO: Implement the basics here with params as private members
    double _line_search();


public:
    virtual void optimize () = 0;
    Optimizer();
    virtual ~Optimizer() = 0;
};

