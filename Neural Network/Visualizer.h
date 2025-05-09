#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Visualizer {
public:
     // Function to draw the structure of the Neural Network
    static void drawNetwork(int inputSize, const std::vector<int>& hiddenSizes, int outputSize);
};

#endif // VISUALIZER_H


