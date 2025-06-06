#pragma once

#include "../common.h"


namespace xt::transforms::signal
{
    class Spectrogram final : public xt::Module
    {
    public:
        Spectrogram();
        explicit Spectrogram(std::vector<xt::Module> transforms);
        auto forward(std::initializer_list<std::any> tensors) -> std::any  override;

    private:
    };
}
