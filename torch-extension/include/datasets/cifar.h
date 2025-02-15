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
        CIFAR10(const std::string &root);
//                CIFAR10(const std::string &root) {
//                    // Load data from the specified root directory
//                    load_data(root);
//                }

        // Override the get method to return a sample
        torch::data::Example<> get(size_t index) override;
//                torch::data::Example<> get(size_t index) override {
//                    // Return the tensor image and its corresponding label
//                    return {data[index].clone(), torch::tensor(labels[index])}; // Clone to ensure tensor validity
//                }

        // Override the size method to return the number of samples
        torch::optional<size_t> size() const override;
//                torch::optional<size_t> size() const override {
//                    return data.size();
//                }

    private:
        std::vector<torch::Tensor> data; // Store image data as tensors
        std::vector<int64_t> labels;      // Store labels
        void load_data(const std::string &root);
//                void load_data(const std::string &root) {
//                    const int num_files = 5;
//                    for (int i = 1; i <= num_files; ++i) {
//                        std::string file_path = root + "/data_batch_" + std::to_string(i) + ".bin";
//                        std::ifstream file(file_path, std::ios::binary);
//                        if (!file.is_open()) {
//                            std::cerr << "Failed to open file: " << file_path << std::endl;
//                            continue;
//                        }
//
//                        for (int j = 0; j < 10000; ++j) {
//                            uint8_t label;
//                            file.read(reinterpret_cast<char *>(&label), sizeof(label));
//                            labels.push_back(static_cast<int64_t>(label));
//
//                            std::vector<uint8_t> image(3072); // 32x32x3 = 3072
//                            file.read(reinterpret_cast<char *>(image.data()), image.size());
//
//                            // Reshape the image to 3x32x32 and convert to a Torch tensor
//                            auto tensor_image = torch::from_blob(image.data(), {3, 32, 32},
//                                                                 torch::kByte).clone(); // Clone to ensure memory management
//                            tensor_image = tensor_image.permute(
//                                    {0, 2, 1}); // Permute to get the correct order (C, H, W)
//
//                            data.push_back(tensor_image); // Store the tensor in the data vector
//                        }
//
//                        file.close();
//                    }
//                }
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
        void load_data( bool train);

    };




}


