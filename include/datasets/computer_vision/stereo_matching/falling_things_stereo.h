#pragma once

#include "../../common.h"


using namespace std;
namespace fs = std::filesystem;

namespace xt::datasets {
    class FallingThingsStereo : public xt::datasets::Dataset {
        /*
        `FallingThings <https://research.nvidia.com/publication/2018-06_falling-things-synthetic-dataset-3d-object-detection-and-pose-estimation>`_ dataset.
        The dataset is expected to have the following structure: ::
        root
            FallingThings
                single
                    dir1
                        scene1
                            _object_settings.json
                            _camera_settings.json
                            image1.left.depth.png
                            image1.right.depth.png
                            image1.left.jpg
                            image1.right.jpg
                            image2.left.depth.png
                            image2.right.depth.png
                            image2.left.jpg
                            image2.right
                            ...
                        scene2
                    ...
                mixed
                    scene1
                        _object_settings.json
                        _camera_settings.json
                        image1.left.depth.png
                        image1.right.depth.png
                        image1.left.jpg
                        image1.right.jpg
                        image2.left.depth.png
                        image2.right.depth.png
                        image2.left.jpg
                        image2.right
                        ...
                    scene2
                    ...
         */
    public :

        explicit FallingThingsStereo(const std::string& root);
        FallingThingsStereo(const std::string& root, xt::datasets::DataMode mode);
        FallingThingsStereo(const std::string& root, xt::datasets::DataMode mode, bool download);
        FallingThingsStereo(const std::string& root, xt::datasets::DataMode mode, bool download,
                   std::unique_ptr<xt::Module> transformer);
        FallingThingsStereo(const std::string& root, xt::datasets::DataMode mode, bool download,
                   std::unique_ptr<xt::Module> transformer,
                   std::unique_ptr<xt::Module> target_transformer);


    private :
        fs::path  url ="https://drive.google.com/open?id=1y4h9T6D9rf6dAmsRwEtfzJdcghCnI_01";
        fs::path dataset_file_name = "fat.zip";
        std::string dataset_file_md5 = "????????????????????????????????";
        fs::path dataset_folder_name = "FallingThings";



        bool download = false;
        fs::path root;
        fs::path dataset_path;

        void load_data();

        void check_resources();

    };
}
