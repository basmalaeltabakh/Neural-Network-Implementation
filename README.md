# Neural Network Implementation 

##  Project Overview
This project is an implementation of a basic **Neural Network** in `C++` that allows the user to:
- Define the structure of the network (Input Layer, Hidden Layers, and Output Layer).
- Choose different Activation Functions: **Sigmoid**, **ReLU**, and **Tanh**.
- Perform **Forward Propagation** to calculate the outputs.
- Visualize the structure of the network after construction.

---
## 📂 File Structure
```
Neural_Network_Implementation
│
├── ActivationFunctions.h       # Header file for activation function declarations
├── ActivationFunctions.cpp     # Implementation of activation functions (Sigmoid, ReLU, Tanh)
│
├── NeuralNetwork.h             # Header file for the Neural Network class
├── NeuralNetwork.cpp           # Implementation of the Neural Network logic (setup, propagation)
│
├── Visualizer.h                # Header file for the Visualizer class
├── Visualizer.cpp              # Implementation of the visualization of the network
│
├── main.cpp                    # Main file to run the program
│
└──  README.md                  # Project documentation
```
---
## ✨ Features
- **Dynamic Network Structure:** User can specify the number of neurons for each layer.
- **Multiple Activation Functions:** Supports:
  - Sigmoid
  - ReLU (Rectified Linear Unit)
  - Tanh (Hyperbolic Tangent)
- **Feedforward Operation:** Forward propagation through the network layers.
- **Clear Visualization:** Displays the architecture of the neural network.

---

##  How to Use
1. When prompted, enter the number of **input neurons** (e.g., 3 for three input features).
2. Specify the number of **hidden layers** (at least 2 layers required).
3. For each hidden layer, specify:
   - The number of neurons.
   - The weights for each neuron.
4. Choose the **Activation Functions** for:
   - Hidden Layers
   - Output Layer
5. The program will:
   - Display the **structure of the network**.
   - Perform **Forward Propagation**.
   - Output the final calculated values.

---

##  How It Works
The neural network follows a **feedforward approach** where:
1. Inputs are propagated through each layer.
2. Neuron outputs are calculated as the weighted sum of inputs passed through an **Activation Function**.
3. The result of each layer is used as input for the next layer.
4. The final result is the output of the network.


---

##  Example Run

```
Example:
-------------
Enter the number of inputs: 3
Input 1: 0.5
Input 2: 1.2
Input 3: -0.7

Enter the number of hidden layers (at least 2): 2

Enter the number of neurons in Layer 1: 2
Enter the weights for Neuron 1 (space-separated): 0.1 0.2 0.3
Enter the weights for Neuron 2 (space-separated): 0.4 0.5 0.6

Enter the number of neurons in Layer 2: 2
Enter the weights for Neuron 1 (space-separated): 0.2 0.3
Enter the weights for Neuron 2 (space-separated): 0.5 0.7

Enter the number of neurons in the Output Layer: 2

Choose Activation Function for Hidden Layers:
1 - Sigmoid
2 - ReLU
3 - Tanh
1

Choose Activation Function for Output Layer:
1 - Sigmoid
2 - ReLU
3 - Tanh
2

Neural Network Structure:
-------------------------
[Input Layer]: 3 neurons
[Hidden Layer 1]: 2 neurons
[Hidden Layer 2]: 2 neurons
[Output Layer]: 2 neurons

Neural Network Output:
0.6457 0.6682
```



