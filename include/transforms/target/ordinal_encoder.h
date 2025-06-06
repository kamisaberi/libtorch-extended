#pragma once

#include "../common.h"


namespace xt::transforms::target
{
    class OrdinalEncoder final : public xt::Module
    {
    public:
        OrdinalEncoder();
        explicit OrdinalEncoder(std::vector<xt::Module> transforms);
        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

    private:
    };
}
