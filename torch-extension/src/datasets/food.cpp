#include "../../include/datasets/food.h"

namespace torch::ext::data::datasets {
    Food101::Food101(const std::string &root, DataMode mode, bool download) : BaseDataset(root, mode, download) {
        check_resources();
    }

    void Food101::check_resources() {
        fs::path archive_file_abs_path = this->root / this->dataset_file_name;
        this->dataset_path = this->root / this->dataset_folder_name;
        if (fs::exists(archive_file_abs_path)) {
            torch::ext::utils::extract(archive_file_abs_path);
        } else {
            fs::path images_path = this->dataset_path / fs::path("images");
            size_t cnt = torch::ext::utils::filesystem::countFiles(images_path, true);
            if (cnt != this->images_number) {
                torch::ext::utils::download(this->url, archive_file_abs_path.string());
                torch::ext::utils::extract(archive_file_abs_path);
            }
        }
    }

    void Food101::load_classes() {
        fs::path meta_path = this->dataset_path / fs::path("meta");
        fs::path classes_file_path = meta_path / fs::path("classes.txt");
        ifstream ifs(classes_file_path.string());
        while (!ifs.eof()) {
            std::string line;
            std::getline(ifs, line);
            line = torch::ext::utils::string::trim(line);
            if (line.empty())
                continue;
            classes_name.push_back(line);
            classes_map.insert({line, classes_name.size() - 1});
        }
    }


    void Food101::load_data() {
        fs::path images_path = this->dataset_path / fs::path("images");
        fs::path meta_path = this->dataset_path / fs::path("meta");

        if (this->mode == DataMode::TRAIN) {
            fs::path train_file_path = meta_path / fs::path("train.txt");
            ifstream ifs(train_file_path.string());
            while (!ifs.eof()) {
                string line;
                getline(ifs, line);
                line = torch::ext::utils::string::trim(line);
                if (line.empty())
                    continue;
                vector<string> tokens = torch::ext::utils::string::split(line, "/");
                string label = tokens[0];
                fs::path img_path = images_path / fs::path(line + ".jpg");
                torch::Tensor tensor = torch::ext::media::opencv::convertImageToTensor(img_path);
                this->data.push_back(tensor);
                this->labels.push_back(classes_map[label]);
            }
        } else {
        }
    }

    // Food101::Food101() {
    //     throw NotImplementedException();
    // }
}
