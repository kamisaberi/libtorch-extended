#pragma once
#include "base.h"
#include "../headers/datasets.h"


namespace xt::data::datasets {
    class ImageNet : BaseDataset {
    public :
        ImageNet(const std::string &root, DataMode mode = DataMode::TRAIN, bool download = false);

        ImageNet(const fs::path &root, DatasetArguments args);

    private :
        void load_data(DataMode mode = DataMode::TRAIN);

        void check_resources(const std::string &root, bool download = false);
    };
}
