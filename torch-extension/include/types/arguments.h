#pragma once
#include <iostream>
#include <type_traits>
#include <vector>
#include <torch/data.h>
#include <torch/csrc/autograd/grad_mode.h>
using namespace std;

enum class DataMode {
    TRAIN = 1,
    VALIDATION = 2,
    TEST = 3,
};

struct DatasetArguments {
    DataMode mode = DataMode::TRAIN;
    bool download = false;
    std::vector<std::shared_ptr<torch::data::transforms::Transform<torch::Tensor, torch::Tensor>>> transforms ={};

};
