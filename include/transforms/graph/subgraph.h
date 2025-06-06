#pragma once

#include "../common.h"


namespace xt::transforms::graph
{
    class Subgraph final : public xt::Module
    {
    public:
        Subgraph();
        explicit Subgraph(std::vector<xt::Module> transforms);
        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

    private:
    };
}
