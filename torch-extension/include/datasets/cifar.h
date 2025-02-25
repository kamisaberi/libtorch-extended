#pragma once
//#include <vector>
#include <fstream>
//#include <iostream>
//#include <string>
#include <filesystem>
//#include <curl/curl.h>
#include <torch/torch.h>
//#include <vector>
//#include <fstream>
//#include <iostream>
//#include <string>
//#include <filesystem>
#include "../utils/downloader.h"
#include "../utils/archiver.h"
#include "../utils/md5.h"

using namespace std;
namespace fs = std::filesystem;


namespace torch::ext::data::datasets {

    class CIFAR10 : public torch::data::Dataset<CIFAR10> {
    public:
        CIFAR10(const std::string &root , bool train= true, bool download = false);

        torch::data::Example<> get(size_t index) override;

        torch::optional<size_t> size() const override;

    private:

        std::vector<torch::Tensor> data; // Store image data as tensors
        std::vector<int64_t> labels;      // Store labels
        std::string download_url = "https://www.cs.toronto.edu/~kriz/cifar-10-binary.tar.gz";
        fs::path archive_file_name = "cifar-10-binary.tar.gz";
        std::string archive_file_md5 = "c32a1d4ab5d03f1284b67883e8d87530";
        fs::path root;
        fs::path dataset_path;
        fs::path dataset_folder_name = "cifar-10-batches-bin";
        vector<fs::path> train_file_names = {
                fs::path("data_batch_1.bin"),
                fs::path("data_batch_2.bin"),
                fs::path("data_batch_3.bin"),
                fs::path("data_batch_4.bin"),
                fs::path("data_batch_5.bin")
        };
        fs::path test_file_name = "test_batch.bin";

        void load_data(bool train = true);
    };


    class CIFAR100 : public torch::data::Dataset<CIFAR100> {
    public:
        CIFAR100(const std::string &root, bool train = true, bool download = false);

        torch::data::Example<> get(size_t index) override;

        torch::optional<size_t> size() const override;

    private:
        std::vector<torch::Tensor> data; // Store image data as tensors
        std::vector<int64_t> labels;      // Store labels
        std::string download_url = "https://www.cs.toronto.edu/~kriz/cifar-100-binary.tar.gz";
        fs::path archive_file_name = "cifar-100-binary.tar.gz";
        std::string archive_file_md5 = "03b5dce01913d631647c71ecec9e9cb8";
        fs::path root;
        fs::path dataset_path;
        fs::path dataset_folder_name = "cifar-100-binary";
        fs::path train_file_name = "train.bin";
        fs::path test_file_name = "test.bin";

        void load_data(bool train);

    };


}


