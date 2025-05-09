
#include "Visualizer.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Visualizer::drawNetwork(int inputSize, const vector<int>& hiddenSizes, int outputSize) {
    cout << "\n--- Neural Network Structure ---\n";

    // Display Input Layer
    cout << "Input Layer (" << inputSize << " neurons):\n";
    for (int i = 0; i < inputSize; ++i) {
        cout << " [I" << i + 1 << "] ";
    }
    cout << "\n\n";

    // Display Hidden Layers
    for (int layer = 0; layer < hiddenSizes.size(); ++layer) {
        cout << "Hidden Layer " << layer + 1 << " (" << hiddenSizes[layer] << " neurons):\n";
        for (int i = 0; i < hiddenSizes[layer]; ++i) {
            cout << " [H" << layer + 1 << "." << i + 1 << "] ";
        }
        cout << "\n\n";
    }

    // Display Output Layer
    cout << "Output Layer (" << outputSize << " neurons):\n";
    for (int i = 0; i < outputSize; ++i) {
        cout << " [O" << i + 1 << "] ";
    }
    cout << "\n";
}
