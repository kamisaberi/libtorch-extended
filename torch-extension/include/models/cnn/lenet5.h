#pragma once
#include <torch/torch.h>
#include "../base.h"
#include <iostream>
#include <vector>


using namespace std;

namespace torch::ext::models {
    struct LeNet5 : torch::ext::models::BaseModel {
    protected:
        torch::nn::Sequential layer1 = nullptr, layer2 = nullptr;
        torch::nn::Linear fc1 = nullptr, fc2 = nullptr, fc3 = nullptr;

    public:
        LeNet5(int num_classes/* classes */, int in_channels = 1/*  input channels */);

        torch::Tensor forward(torch::Tensor x) const override;
    };
}
