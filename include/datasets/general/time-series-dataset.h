#pragma once


#include "../base/base.h"
#include "../../headers/datasets.h"


namespace xt::data::datasets {



    class CSVDataset : public BaseDataset {
    public :
        CSVDataset(const std::string &file_path);
        CSVDataset(const std::string &file_path,DataMode mode);
        CSVDataset(const std::string &file_path,DataMode mode , vector<std::function<torch::Tensor(torch::Tensor)>> transforms);

    private:
        vector<string> labels_name;
        bool load_sub_folders = false;
        void load_data();
    };


    class StackedCSVDataset : public BaseDataset {
    public :
        StackedCSVDataset(const std::string &folder_path);
        StackedCSVDataset(const std::string &folder_path,DataMode mode);
        StackedCSVDataset(const std::string &folder_path,DataMode mode, bool load_sub_folders);
        StackedCSVDataset(const std::string &folder_path,DataMode mode, bool load_sub_folders , vector<std::function<torch::Tensor(torch::Tensor)>> transforms);

    private:
        vector<string> labels_name;
        bool load_sub_folders = false;
        void load_data();
    };



}
