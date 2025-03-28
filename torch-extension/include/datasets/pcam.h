#pragma once
#include "../headers/datasets.h"
#include "base.h"



namespace xt::data::datasets {
    class PCAM : BaseDataset {
    public :
        PCAM(const std::string &root, DataMode mode = DataMode::TRAIN, bool download = false);

        PCAM(const fs::path &root, DatasetArguments args);

    private :
        std::tuple<fs::path, std::string, std::string>  t = {fs::path("camelyonpatch_level_2_split_train_x.h5"),"1Ka0XfEMiwgCYPdTI-vv6eUElOBnKFKQ2","1571f514728f59376b705fc836ff4b63"};
        std::map<std::string, std::map<std::string, std::tuple<fs::path, std::string, std::string> >> resources = {
                {"train",{
                    {"images", {fs::path("camelyonpatch_level_2_split_train_x.h5"),"1Ka0XfEMiwgCYPdTI-vv6eUElOBnKFKQ2","1571f514728f59376b705fc836ff4b63"} },
                    {"targets", {fs::path("camelyonpatch_level_2_split_train_y.h5"),"1269yhu3pZDP8UYFQs-NYs3FPwuK-nGSG","35c2d7259d906cfc8143347bb8e05be7"} },
                }},
                {"test",{
                    {"images", {fs::path("camelyonpatch_level_2_split_test_x.h5"),"1qV65ZqZvWzuIVthK8eVDhIwrbnsJdbg_","d8c2d60d490dbd479f8199bdfa0cf6ec"} },
                    {"targets", {fs::path("camelyonpatch_level_2_split_test_y.h5"),"17BHrSrwWKjYsOgTMmoqrIjDy6Fa2o_gP","60a7035772fbdb7f34eb86d4420cf66a"} },
                }},
                {"val",{
                    {"images", {fs::path("camelyonpatch_level_2_split_valid_x.h5"),"1hgshYGWK8V-eGRy8LToWJJgDU_rXWVJ3","d5b63470df7cfa627aeec8b9dc0c066e"} },
                    {"targets", {fs::path("camelyonpatch_level_2_split_valid_y.h5"),"1bH8ZRbhSVAhScTS0p9-ZzGnX91cHT3uO","2b85f58b927af9964a4c15b8f7e8f179"} },
                }}


        };
        fs::path dataset_folder_name = "pcam";
        void load_data(DataMode mode = DataMode::TRAIN);

        void check_resources(const std::string &root, bool download = false);


    };
}
