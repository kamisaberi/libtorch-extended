#pragma once

#include "../common.h"


namespace xt::transforms::image
{
    class Upscale final : public xt::Module
    {
    public:
        Upscale();
        explicit Upscale(std::vector<xt::Module> transforms);
        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

    private:
    };
}
