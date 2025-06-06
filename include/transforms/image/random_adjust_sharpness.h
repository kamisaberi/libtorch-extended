#pragma once

#include "../common.h"


namespace xt::transforms::image
{
    class RandomAdjustSharpness final : public xt::Module
    {
    public:
        RandomAdjustSharpness();
        explicit RandomAdjustSharpness(std::vector<xt::Module> transforms);
        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

    private:
    };
}
