#pragma once
#include "../../common.h"


namespace xt::models
{
    struct DeepLabV1 : xt::Cloneable<DeepLabV1>
    {
    private:

    public:
        DeepLabV1(int num_classes /* classes */, int in_channels = 3/* input channels */);

        DeepLabV1(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;
        void reset() override;
    };

    struct DeepLabV2 : xt::Cloneable<DeepLabV2>
    {
    private:

    public:
        DeepLabV2(int num_classes /* classes */, int in_channels = 3/* input channels */);

        DeepLabV2(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;
        void reset() override;
    };


    struct DeepLabV3 : xt::Cloneable<DeepLabV3>
    {
    private:

    public:
        DeepLabV3(int num_classes /* classes */, int in_channels = 3/* input channels */);

        DeepLabV3(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;
        void reset() override;
    };

    struct DeepLabV3Plus : xt::Cloneable<DeepLabV3Plus>
    {
    private:

    public:
        DeepLabV3Plus(int num_classes /* classes */, int in_channels = 3/* input channels */);

        DeepLabV3Plus(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;
        void reset() override;
    };
}
