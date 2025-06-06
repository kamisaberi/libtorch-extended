#pragma once

#include "../../common.h"


namespace xt::models
{
    struct DallEV1 : xt::Cloneable<DallEV1>
    {
    private:

    public:
        DallEV1(int num_classes /* classes */, int in_channels = 3/* input channels */);

        DallEV1(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;
        void reset() override;
    };

    struct DallEV2 : xt::Cloneable<DallEV2>
    {
    private:

    public:
        DallEV2(int num_classes /* classes */, int in_channels = 3/* input channels */);

        DallEV2(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;
        void reset() override;
    };

    struct DallEV3 : xt::Cloneable<DallEV3>
    {
    private:

    public:
        DallEV3(int num_classes /* classes */, int in_channels = 3/* input channels */);

        DallEV3(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;
        void reset() override;
    };

}