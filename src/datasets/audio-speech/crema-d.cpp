#include "../../../include/datasets/audio-speech/crema-d.h"

namespace xt::data::datasets {

    CremaD::CremaD(const std::string &root): CremaD::CremaD(root, DataMode::TRAIN, false) {
    }

    CremaD::CremaD(const std::string &root, DataMode mode): CremaD::CremaD(root, mode, false) {
    }

    CremaD::CremaD(const std::string &root, DataMode mode, bool download) : BaseDataset(root, mode, download) {
        throw std::runtime_error("CremaD: CremaD not implemented");
    }


    CremaD::CremaD(const std::string &root, DataMode mode, bool download,
                         TransformType transforms) : BaseDataset(root, mode, download, transforms) {
        throw std::runtime_error("CremaD: CremaD not implemented");
    }


}
