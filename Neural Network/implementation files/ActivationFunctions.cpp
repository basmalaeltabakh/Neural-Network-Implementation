#include "ActivationFunctions.h"

// Sigmoid Activation Function: It maps any real-valued number into the range (0, 1).
// Formula: sigmoid(x) = 1 / (1 + exp(-x))
double ActivationFunctions::sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// ReLU Activation Function: It maps any negative values to 0 and keeps positive values as they are.
// Formula: relu(x) = max(0, x)
double ActivationFunctions::relu(double x) {
    return (x > 0) ? x : 0;  // If x > 0, return x; otherwise, return 0
}

// Tanh Activation Function: It maps any real-valued number into the range (-1, 1).
// Formula: tanh(x) = (exp(x) - exp(-x)) / (exp(x) + exp(-x))
double ActivationFunctions::tanh_func(double x) {
    return tanh(x);
}
