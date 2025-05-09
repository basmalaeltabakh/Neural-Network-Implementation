#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <iostream>
#include <vector>
#include "ActivationFunctions.h"

using namespace std;

class NeuralNetwork {
private:
    vector<vector<vector<double>>> hiddenLayers;
    vector<double> inputs;
    vector<double> outputLayer;
    int numHiddenLayers;
    double (*hidden_activation)(double);
    double (*output_activation)(double);

public:
    NeuralNetwork();
    void setInputLayer(int numInputs);
    void setHiddenLayers();
    void setOutputLayer();
    void setActivationFunctions();
    vector<double> forwardPropagation();
    void displayOutput(const vector<double> &output);
    std::vector<int> getHiddenLayerSizes() const;
    int getOutputLayerSize() const;
};

#endif // NEURAL_NETWORK_H
