#pragma once
#include "include/models/common.h"

namespace xt::models
{
    struct BERT : xt::Cloneable<BERT>
    {
    private:

    public:
        BERT(int num_classes /* classes */, int in_channels = 3/* input channels */);

        BERT(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        torch::Tensor forward(torch::Tensor x) const override;
        void reset() override;
    };

}