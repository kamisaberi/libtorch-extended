#pragma once

#include "../../common.h"


namespace xt::models
{
    struct CAE : xt::Cloneable<CAE>
    {
    private:

    public:
        CAE(int num_classes /* classes */, int in_channels = 3/* input channels */);

        CAE(int num_classes, int in_channels, std::vector<int64_t> input_shape);


        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;
        void reset() override;
    };

}