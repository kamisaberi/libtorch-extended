#include "include/transforms/general/random_undersampling.h"

namespace xt::transforms::general {

    RandomUnderSampling::RandomUnderSampling() = default;

    auto RandomUnderSampling::forward(std::initializer_list <std::any> tensors) -> std::any {
        return torch::zeros(10);
    }


    // RandomUnderSampling::RandomUnderSampling(std::function<torch::Tensor(torch::Tensor)> transform) : xt::Module(), transform(transform) {
    // }
    //
    // torch::Tensor RandomUnderSampling::forward(torch::Tensor input) const {
    //     return transform(input);
    // }

}