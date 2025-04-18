#pragma once

#include "../base/base.h"
#include "../../headers/datasets.h"


namespace xt::data::datasets {
    class UrbanSound : BaseDataset {
    public :
        explicit UrbanSound(const std::string &root);

        UrbanSound(const std::string &root, DataMode mode);

        UrbanSound(const std::string &root, DataMode mode, bool download);

        UrbanSound(const std::string &root, DataMode mode, bool download, TransformType transforms);

    private :
        void load_data();

        void check_resources();
    };
}
