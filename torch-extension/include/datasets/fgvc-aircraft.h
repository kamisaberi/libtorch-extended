#pragma once
#include "../headers/datasets.h"
#include "base.h"


namespace xt::data::datasets {
    class FGVCAircraft :public BaseDataset {
    public :
        FGVCAircraft(const std::string &root, DataMode mode = DataMode::TRAIN, bool download = false);

        FGVCAircraft(const fs::path &root, DatasetArguments args);

    private :
        void load_data(DataMode mode = DataMode::TRAIN);

        void check_resources(const std::string &root, bool download = false);
    };
}
