#pragma once
#include <torch/torch.h>
#include <iostream>
#include <vector>


using namespace std;
namespace torch::ext::models {

    struct LeNet5 : torch::nn::Module {
        torch::nn::Sequential layer1 = nullptr, layer2 = nullptr;
        torch::nn::Linear fc1 = nullptr, fc2 = nullptr, fc3 = nullptr;

        LeNet5(int num_classes);

        torch::Tensor forward(torch::Tensor x);
    };
}

