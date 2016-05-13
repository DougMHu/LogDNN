# Log-Domain DNN in C++

LogDNN is the beginnings of an implementation of a deep neural network using Log-Domain Arithmetic. This began as project to port the [DASANN library][dasann] from Python to C++. The purpose is to simulate Log-Domain Arithmetic much faster than the Python library, which currently takes ~7 days to run one simulation.

The Network class implements a random weight matrix generator. The feedforward and backpropagation functions have not yet been implemented. The class structure follows closely with the Network class implemented in the [DASANN-simulations][dasann] project.

[dasann]: https://github.com/DougMHu/DASANN-simulations