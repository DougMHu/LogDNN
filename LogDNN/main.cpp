//
//  main.cpp
//  LogDNN
//
//  Created by Douglas Hu on 4/17/16.
//  Copyright © 2016 Douglas Hu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <chrono>

typedef std::vector<double> Row;
typedef std::vector<Row> Matrix;

class Network
{
public:
    // constructor
    Network(int num_in, std::vector<int> sizes_in) {
        this->num_layers = num_in;
        this->sizes = sizes_in;
        this->weights = default_weight_initializer();
    }
    // destructor
    ~Network() {
        
    }

//protected:
    int num_layers;
    std::vector<int> sizes;
    std::list<Matrix> weights;
    
    std::list<Matrix> default_weight_initializer() {
        
        // Initialize randomness generators
        unsigned seedx = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seedx);
        // generators for noise
        std::normal_distribution<double> noise (0.0,1.0);
        //std::cout << noise(generator) << std::endl;

        // create weight matrices
        Row row(10);
        row.resize(10);
        std::cout << row.capacity(); // capacity is 10 columns
        for (int i = 0; i < 10; ++i) {
            row.push_back(noise(generator));
        }
        
        Matrix weight;
        weight.reserve(10); // make room for 10 rows
        weight.push_back(row);
        std::list<Matrix> weights;
        weights.push_back(weight);
        
        std::cout<<weight.capacity()<<std::endl;
        std::cout<<weight.size()<<std::endl;
        
        //std::vector<double> weights(1,1);
        return weights;
    }
};


int main(int argc, const char * argv[]) {
    // initialize Network parameters
    int num = 3;
    int layers[] = {784,30,10};
    std::vector<int> sizes(layers, layers + sizeof(layers) / sizeof(int));
    Network net = Network(num,sizes);
    
    // print Network layers
    for (std::vector<int>::iterator it = net.sizes.begin(); it != net.sizes.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    
    // print weights
    for (std::list<Matrix>::iterator it = net.weights.begin(); it != net.weights.end(); ++it) {
        for (std::vector<Row>::iterator it2 = it->begin(); it2 != it->end(); ++it2) {
            for (std::vector<double>::iterator it3 = it2->begin(); it3 != it2->end(); ++it3)
                std::cout << ' ' << *it3;
            std::cout << '\n';
        }
    }
        //std::cout << ' ' << *it;
    //std::cout << '\n';
    
    // Initialize randomness generators
    unsigned seedx = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seedx);
    // generators for noise
   	std::normal_distribution<double> noise (0.0,1.0);
    std::cout << noise(generator) << std::endl;
    
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
