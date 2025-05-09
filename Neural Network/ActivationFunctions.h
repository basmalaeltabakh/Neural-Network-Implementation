#ifndef ACTIVATION_FUNCTIONS_H
#define ACTIVATION_FUNCTIONS_H

#include <cmath>

class ActivationFunctions {
public:
    static double sigmoid(double x);
    static double relu(double x);
    static double tanh_func(double x);
};

#endif // ACTIVATION_FUNCTIONS_H
