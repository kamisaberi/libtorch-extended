#pragma once

#include "../common.h"


namespace xt::transforms::image
{
    class TruncationTrick final : public xt::Module
    {
    public:
        TruncationTrick();
        explicit TruncationTrick(std::vector<xt::Module> transforms);
        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

    private:
    };
}
