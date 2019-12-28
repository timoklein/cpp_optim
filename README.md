# cpp_optim
This repository contains basic implementations of numerical optimization algorithms for nonlinear problems. As testbed two simple problems are provided.

##  Getting started
You need a C++ compiler (like GCC on Linux) as well as the [Eigen3](http://eigen.tuxfamily.org/index.php?title=Main_Page) template library. The code in this repo uses Eigen 3.3.7.

## Implemented Optimization Algorithms
This repo implements three numerical optimization algorithms for nonlinear functions. For each algorithm the step size is determined by backtracking line search using the [Armijo-rule](https://scicomp.stackexchange.com/questions/5478/confusion-about-armijo-rule).  

1. __Plain Gradient Descent__  
    This is a plain implementation of the _steepest descent method_. Further information can be read [here](https://en.wikipedia.org/wiki/Gradient_descent). It uses the negative gradient of the function $f$ at a point $x$ as search direction: $d^k = - \nabla f(x^k)$.

2. __Gauss-Newton Method__  
    The _Gauss-Newton algorithm_ is a method for finding the minimum of nonlinear least squares problems of the shape $f(x) = \frac{1}{2}||r(x)||^2_2$ where $r(x)$ is a linear function. The objective is thus convex. The search direction in the _Gauss-Newton-Algorithm_ is determined by $d^k = - \nabla_{A^k} f(x^k)$ with $A^k = \nabla r (x^k) Dr(x^k)$. $Dr(x^k)$ here denotes the Jacobian and $\nabla r (x^k)$ the transposed Jacobian. For more information, read [here](https://en.wikipedia.org/wiki/Gauss%E2%80%93Newton_algorithm).

3. __Conjugate Gradient Method__  
    This is an implementation of the [nonlinear conjugate gradient method](https://en.wikipedia.org/wiki/Nonlinear_conjugate_gradient_method). The search direction here is given as 
    $d^{k+1} = - \nabla f(x^{k+1}) + \alpha \cdot d^k$. The parameter $\alpha$ is calculated according to the formula of Fletcher-Reeves: $\alpha = \frac{ ||\nablaf(x^{k+1})||^2_2 }{ ||\nablaf(x^k)||^2_2 }$.


## Example problems



## Project structure: 
    
    .
    |
    |
    ├── src   # Contains algorithm and function implementations
    |   ├── conjugategradient.hpp    # Fletcher-Reeves Conjugate Gradient Algorithm
    |   ├── functions.cpp    # Implementations of functions and their gradients
    |   ├── functions.hpp    # Function headers
    |   ├── gaussnewton.hpp    # Gauss-Newton algorithm for Linear least squares problems
    |   ├── gradientdescent.hpp    # Plain gradient descent optimizer
    |   ├── optimizer.hpp    # Optimizer base class implementing backtracking line search and print functionality
    |   └── returnvalue.hpp    # Result data container
    |
    |
    └── main    # Main driver for the example problems
    
