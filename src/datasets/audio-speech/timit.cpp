#include "../../../include/datasets/audio-speech/timit.h"

namespace xt::data::datasets {

    TIMIT::TIMIT(const std::string &root): CMUArctic::CMUArctic(root, DataMode::TRAIN, false) {
    }

    TIMIT::TIMIT(const std::string &root, DataMode mode): CMUArctic::CMUArctic(root, mode, false) {
    }

    TIMIT::TIMIT(const std::string &root, DataMode mode, bool download) : BaseDataset(root, mode, download) {
        throw std::runtime_error("TIMIT: TIMIT not implemented");
    }


    TIMIT::TIMIT(const std::string &root, DataMode mode, bool download,
                         TransformType transforms) : BaseDataset(root, mode, download, transforms) {
        throw std::runtime_error("TIMIT: TIMIT not implemented");
    }


}
