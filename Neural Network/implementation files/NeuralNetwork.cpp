#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork() : numHiddenLayers(0), hidden_activation(nullptr), output_activation(nullptr) {}

void NeuralNetwork::setInputLayer(int numInputs) {
    inputs.resize(numInputs); // Resize the vector to hold the input neurons
    cout << "Enter the values for each input neuron:\n";
    for (int i = 0; i < numInputs; ++i) {
        cout << "Input " << i + 1 << ": ";
        // Input validation to ensure the user enters valid numbers
        while (!(cin >> inputs[i])) {
            cin.clear(); // Clear the error flag
            cin.ignore(1000, '\n');// Ignore invalid input
            cout << "Invalid input. Please enter a number: ";
        }
    }
}

void NeuralNetwork::setHiddenLayers() {
    cout << "\nEnter the number of hidden layers (at least 2): ";
    // Input validation for number of hidden layers
    while (!(cin >> numHiddenLayers) || numHiddenLayers < 2) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "You must have at least 2 hidden layers. Try again: ";
    }

    hiddenLayers.resize(numHiddenLayers); // Resize for the number of layers

    int numInputs = inputs.size();
    for (int layer = 0; layer < numHiddenLayers; ++layer) {
        int numNeurons;
        cout << "\nEnter the number of neurons in Layer " << layer + 1 << ": ";
        // Input validation for number of neurons
        while (!(cin >> numNeurons) || numNeurons <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid number of neurons. Try again: ";
        }

        hiddenLayers[layer].resize(numNeurons);

        for (int neuron = 0; neuron < numNeurons; ++neuron) {
            cout << "Enter the weights for Neuron " << neuron + 1 << " (space-separated): ";
            hiddenLayers[layer][neuron].resize(numInputs);
            for (int weight = 0; weight < numInputs; ++weight) {
                while (!(cin >> hiddenLayers[layer][neuron][weight])) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid weight. Please enter a number: ";
                }
            }
        }
        numInputs = numNeurons;// Update the input size for the next layer
    }
}

void NeuralNetwork::setOutputLayer() {
    int numOutputs;
    cout << "\nEnter the number of neurons in the Output Layer: ";
    cin >> numOutputs;
    outputLayer.resize(numOutputs);
}

void NeuralNetwork::setActivationFunctions() {
    // Choose activation for Hidden Layers
    int choice;
    cout << "\nChoose Activation Function for Hidden Layers:\n1 - Sigmoid\n2 - ReLU\n3 - Tanh\n";
    cin >> choice;

    switch (choice) {
        case 1: hidden_activation = ActivationFunctions::sigmoid; break;
        case 2: hidden_activation = ActivationFunctions::relu; break;
        case 3: hidden_activation = ActivationFunctions::tanh_func; break;
        default: hidden_activation = ActivationFunctions::sigmoid;
    }

    cout << "\nChoose Activation Function for Output Layer:\n1 - Sigmoid\n2 - ReLU\n3 - Tanh\n";
    cin >> choice;

    switch (choice) {
        case 1: output_activation = ActivationFunctions::sigmoid; break;
        case 2: output_activation = ActivationFunctions::relu; break;
        case 3: output_activation = ActivationFunctions::tanh_func; break;
        default: output_activation = ActivationFunctions::sigmoid;
    }
}

vector<double> NeuralNetwork::forwardPropagation() {
    vector<double> currentValues = inputs;// Start with the input values
     // Loop through each hidden layer
    for (int layer = 0; layer < numHiddenLayers; ++layer) {
        vector<double> nextValues(hiddenLayers[layer].size());

        for (int neuron = 0; neuron < hiddenLayers[layer].size(); ++neuron) {
            double sum = 0.0;
            // Multiply inputs by their corresponding weights
            for (int weight = 0; weight < currentValues.size(); ++weight) {
                sum += hiddenLayers[layer][neuron][weight] * currentValues[weight];
            }
            // Apply the activation function and store the result
            nextValues[neuron] = hidden_activation(sum);
        }
        currentValues = nextValues;// Update the current values for the next layer
    }
 // Apply the output activation function to the final output layer
    for (int i = 0; i < outputLayer.size(); ++i) {
        outputLayer[i] = output_activation(currentValues[i]);
    }

    return outputLayer;
}
std::vector<int> NeuralNetwork::getHiddenLayerSizes() const {
    std::vector<int> sizes;
    for (const auto& layer : hiddenLayers) {
        sizes.push_back(layer.size());
    }
    return sizes;
}

int NeuralNetwork::getOutputLayerSize() const {
    return outputLayer.size();
}
void NeuralNetwork::displayOutput(const std::vector<double>& output) {
    std::cout << "Neural Network Output:\n";
    for (const auto& value : output) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
