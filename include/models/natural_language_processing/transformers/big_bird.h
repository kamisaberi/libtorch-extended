#pragma once
#include "include/models/common.h"

namespace xt::models
{
    struct BigBird : xt::Cloneable<BigBird>
    {
    private:

    public:
        BigBird(int num_classes /* classes */, int in_channels = 3/* input channels */);

        BigBird(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        torch::Tensor forward(torch::Tensor x) const override;
        void reset() override;
    };

}