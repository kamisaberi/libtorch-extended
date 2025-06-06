#pragma once

#include "../common.h"


namespace xt::transforms::target
{
    class Clipper final : public xt::Module
    {
    public:
        Clipper();
        explicit Clipper(std::vector<xt::Module> transforms);
        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

    private:
    };
}
