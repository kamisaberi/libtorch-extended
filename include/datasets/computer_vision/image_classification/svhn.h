#pragma once

#include "../../common.h"


using namespace std;
namespace fs = std::filesystem;


namespace xt::datasets {
    class SVHN : xt::datasets::Dataset {
        /*
        """`SVHN <http://ufldl.stanford.edu/housenumbers/>`_ Dataset.
    Note: The SVHN dataset assigns the label `10` to the digit `0`. However, in this Dataset,
    we assign the label `0` to the digit `0` to be compatible with PyTorch loss functions which
    expect the class labels to be in the range `[0, C-1]`

    .. warning::

        This class needs `scipy <https://docs.scipy.org/doc/>`_ to load data from `.mat` format.

    Args:
        root (str or ``pathlib.Path``): Root directory of the dataset where the data is stored.
        split (string): One of {'train', 'test', 'extra'}.
            Accordingly dataset is selected. 'extra' is Extra training set.
        transform (callable, optional): A function/transform that takes in a PIL image
            and returns a transformed version. E.g, ``transforms.RandomCrop``
        target_transform (callable, optional): A function/transform that takes in the
            target and transforms it.
        download (bool, optional): If true, downloads the dataset from the internet and
            puts it in root directory. If dataset is already downloaded, it is not
            downloaded again.

    """

         */
    public :

        explicit SVHN(const std::string& root);
        SVHN(const std::string& root, xt::datasets::DataMode mode);
        SVHN(const std::string& root, xt::datasets::DataMode mode, bool download);
        SVHN(const std::string& root, xt::datasets::DataMode mode, bool download,
                   std::unique_ptr<xt::Module> transformer);
        SVHN(const std::string& root, xt::datasets::DataMode mode, bool download,
                   std::unique_ptr<xt::Module> transformer,
                   std::unique_ptr<xt::Module> target_transformer);


    private:
        std::map<std::string, std::tuple<fs::path, fs::path, std::string>> resources = {
                {"train", {
                                  fs::path("http://ufldl.stanford.edu/housenumbers/train_32x32.mat"),
                                  fs::path("train_32x32.mat"),
                                  "e26dedcc434d2e4c54c9b2d4a06d8373"}
                },
                {"test",  {
                                  fs::path("http://ufldl.stanford.edu/housenumbers/test_32x32.mat"),
                                  fs::path("test_32x32.mat"),
                                  "eb5a983be6a315427106f1b164d9cef3"}
                },
                {"extra", {
                                  fs::path("http://ufldl.stanford.edu/housenumbers/extra_32x32.mat"),
                                  fs::path("extra_32x32.mat"),
                                  "a93ce644f1a588dc4d68dda5feec44a7"
                          }
                }
        };


        // TODO fs::path dataset_folder_name
        fs::path dataset_folder_name = "?";

        bool download = false;
        fs::path root;
        fs::path dataset_path;

        void load_data();

        void check_resources();


    };
}
