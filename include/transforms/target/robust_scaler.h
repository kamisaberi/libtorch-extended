#pragma once

#include "../common.h"


namespace xt::transforms::target
{
    class RobustScaler final : public xt::Module
    {
    public:
        RobustScaler();
        explicit RobustScaler(std::vector<xt::Module> transforms);
        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

    private:
    };
}
