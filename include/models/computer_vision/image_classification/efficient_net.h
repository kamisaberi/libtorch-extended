#pragma once

#include "../../common.h"



using namespace std;


namespace xt::models
{
    struct EfficientNetB0 : xt::Cloneable<EfficientNetB0>
    {
    private:

    public:
        EfficientNetB0(int num_classes /* classes */, int in_channels = 3/* input channels */);

        EfficientNetB0(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;
        void reset() override;
    };


    struct EfficientNetB1 : xt::Cloneable<EfficientNetB1>
    {
    private:

    public:
        EfficientNetB1(int num_classes /* classes */, int in_channels = 3/* input channels */);

        EfficientNetB1(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

        void reset() override;
    };


    struct EfficientNetB2 : xt::Cloneable<EfficientNetB2>
    {
    private:

    public:
        EfficientNetB2(int num_classes /* classes */, int in_channels = 3/* input channels */);

        EfficientNetB2(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

        void reset() override;
    };

    struct EfficientNetB3 : xt::Cloneable<EfficientNetB3>
    {
    private:

    public:
        EfficientNetB3(int num_classes /* classes */, int in_channels = 3/* input channels */);

        EfficientNetB3(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

        void reset() override;
    };

    struct EfficientNetB4 : xt::Cloneable<EfficientNetB4>
    {
    private:

    public:
        EfficientNetB4(int num_classes /* classes */, int in_channels = 3/* input channels */);

        EfficientNetB4(int num_classes, int in_channels, std::vector<int64_t> input_shape);
        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

        void reset() override;
    };

    struct EfficientNetB5 : xt::Cloneable<EfficientNetB5>
    {
    private:

    public:
        EfficientNetB5(int num_classes /* classes */, int in_channels = 3/* input channels */);

        EfficientNetB5(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

        void reset() override;
    };

    struct EfficientNetB6 : xt::Cloneable<EfficientNetB6>
    {
    private:

    public:
        EfficientNetB6(int num_classes /* classes */, int in_channels = 3/* input channels */);

        EfficientNetB6(int num_classes, int in_channels, std::vector<int64_t> input_shape);

        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

        void reset() override;
    };

    struct EfficientNetB7 : xt::Cloneable<EfficientNetB7>
    {
    private:

    public:
        EfficientNetB7(int num_classes /* classes */, int in_channels = 3/* input channels */);

        EfficientNetB7(int num_classes, int in_channels, std::vector<int64_t> input_shape);
        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;
        void reset() override;
    };

}
