#pragma once
#include "include/models/common.h"

namespace xt::models
{
    struct DDIM : xt::Cloneable<DDIM>
    {
    private:

    public:
        DDIM(int num_classes /* classes */, int in_channels = 3/* input channels */);

        DDIM(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        torch::Tensor forward(torch::Tensor x) const override;
        void reset() override;
    };

}