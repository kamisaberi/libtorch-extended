#pragma once

#include "../common.h"


namespace xt::transforms::image
{
    class RandomPosterize final : public xt::Module
    {
    public:
        RandomPosterize();
        explicit RandomPosterize(std::vector<xt::Module> transforms);
        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

    private:
    };
}
