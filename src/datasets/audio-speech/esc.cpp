#include "../../../include/datasets/audio-speech/esc.h"

namespace xt::data::datasets {

    ESC::ESC(const std::string &root): ESC::ESC(root, DataMode::TRAIN, false) {
    }

    ESC::ESC(const std::string &root, DataMode mode): ESC::ESC(root, mode, false) {
    }

    ESC::ESC(const std::string &root, DataMode mode, bool download) : BaseDataset(root, mode, download) {
        throw std::runtime_error("ESC: ESC not implemented");
    }


    ESC::ESC(const std::string &root, DataMode mode, bool download,
                         TransformType transforms) : BaseDataset(root, mode, download, transforms) {
        throw std::runtime_error("ESC: ESC not implemented");
    }


}
