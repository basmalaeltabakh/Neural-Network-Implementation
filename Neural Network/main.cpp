#include <iostream>
#include <vector>
#include "NeuralNetwork.h"
#include "Visualizer.h"

using namespace std;

int main() {
    NeuralNetwork nn;
    Visualizer visualizer;

    // Set up the neural network layers and activation functions
    int numInputs;
    cout << "Enter the number of input neurons: ";
    cin >> numInputs;
    nn.setInputLayer(numInputs);

    nn.setHiddenLayers();

    nn.setOutputLayer();

    nn.setActivationFunctions();

    // After the network is set up, draw the network structure
    visualizer.drawNetwork(numInputs, nn.getHiddenLayerSizes(), nn.getOutputLayerSize());

    return 0;
}

