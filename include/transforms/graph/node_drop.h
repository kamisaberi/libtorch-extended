#pragma once

#include "../common.h"


namespace xt::transforms::graph
{
    class NodeDrop final : public xt::Module
    {
    public:
        NodeDrop();
        explicit NodeDrop(std::vector<xt::Module> transforms);
        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

    private:
    };
}
