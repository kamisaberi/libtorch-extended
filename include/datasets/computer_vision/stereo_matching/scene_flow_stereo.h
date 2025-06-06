#pragma once

#include "../../common.h"


using namespace std;
namespace fs = std::filesystem;

namespace xt::datasets {
   class SceneFlowStereo : xt::datasets::Dataset {
       /*
            """Dataset interface for `Scene Flow <https://lmb.informatik.uni-freiburg.de/resources/datasets/SceneFlowDatasets.en.html>`_ datasets.
    This interface provides access to the `FlyingThings3D, `Monkaa` and `Driving` datasets.

    The dataset is expected to have the following structure: ::

        root
            SceneFlow
                Monkaa
                    frames_cleanpass
                        scene1
                            left
                                img1.png
                                img2.png
                            right
                                img1.png
                                img2.png
                        scene2
                            left
                                img1.png
                                img2.png
                            right
                                img1.png
                                img2.png
                    frames_finalpass
                        scene1
                            left
                                img1.png
                                img2.png
                            right
                                img1.png
                                img2.png
                        ...
                        ...
                    disparity
                        scene1
                            left
                                img1.pfm
                                img2.pfm
                            right
                                img1.pfm
                                img2.pfm
                FlyingThings3D
                    ...
                    ...

    Args:
        root (str or ``pathlib.Path``): Root directory where SceneFlow is located.
        variant (string): Which dataset variant to user, "FlyingThings3D" (default), "Monkaa" or "Driving".
        pass_name (string): Which pass to use, "clean" (default), "final" or "both".
        transforms (callable, optional): A function/transform that takes in a sample and returns a transformed version.

    """

        */

   public :

       explicit SceneFlowStereo(const std::string& root);
       SceneFlowStereo(const std::string& root, xt::datasets::DataMode mode);
       SceneFlowStereo(const std::string& root, xt::datasets::DataMode mode, bool download);
       SceneFlowStereo(const std::string& root, xt::datasets::DataMode mode, bool download,
                  std::unique_ptr<xt::Module> transformer);
       SceneFlowStereo(const std::string& root, xt::datasets::DataMode mode, bool download,
                  std::unique_ptr<xt::Module> transformer,
                  std::unique_ptr<xt::Module> target_transformer);

   private :
       fs::path dataset_folder_name = fs::path("SceneFlow") ;


       bool download = false;
       fs::path root;
       fs::path dataset_path;


       void load_data();

       void check_resources();

   };
}
