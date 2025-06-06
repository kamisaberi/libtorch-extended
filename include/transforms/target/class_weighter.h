#pragma once

#include "../common.h"


namespace xt::transforms::target

{
    class ClassWeighter final : public xt::Module
    {
    public:
        ClassWeighter();
        explicit ClassWeighter(std::vector<xt::Module> transforms);
        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

    private:
    };
}
