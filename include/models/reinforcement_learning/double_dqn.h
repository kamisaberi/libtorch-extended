#pragma once
#include "../common.h"

namespace xt::models
{
    struct DoubleDQN : xt::Cloneable<DoubleDQN>
    {
    private:

    public:
        DoubleDQN(int num_classes /* classes */, int in_channels = 3/* input channels */);

        DoubleDQN(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;
        void reset() override;
    };

}