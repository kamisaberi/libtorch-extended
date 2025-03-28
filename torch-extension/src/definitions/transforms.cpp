#include "../../include/definitions/transforms.h"

namespace xt::data::transforms {
    torch::Tensor resize_tensor(const torch::Tensor &tensor, const std::vector<int64_t> &size) {
        return torch::nn::functional::interpolate(
            tensor.unsqueeze(0),
            torch::nn::functional::InterpolateFuncOptions().size(size).mode(torch::kBilinear).align_corners(false)
        ).squeeze(0);
    }

    torch::Tensor pad_tensor(const torch::Tensor &tensor, int size) {
        std::vector<int64_t> ssize = {size, size};
        return torch::nn::functional::interpolate(
            tensor.unsqueeze(0),
            torch::nn::functional::InterpolateFuncOptions().size(ssize).mode(torch::kBilinear).align_corners(false)
        ).squeeze(0);
    }

    torch::Tensor grayscale_image(const torch::Tensor &tensor) {
        return torch::nn::functional::interpolate(
            tensor.unsqueeze(0),
            torch::nn::functional::InterpolateFuncOptions().mode(torch::kBilinear).align_corners(false)
        ).squeeze(0);
    }

    torch::Tensor grayscale_to_rgb(const torch::Tensor &tensor) {
        torch::Tensor gray = tensor.dim() == 3 ? tensor.unsqueeze(1) : tensor; // Ensure [N, 1, H, W]
        return gray.repeat({1, 3, 1, 1}); // [N, 1, H, W] -> [N, 3, H, W]
    }

    torch::data::transforms::Lambda<torch::data::Example<> > resize(std::vector<int64_t> size) {
        return torch::data::transforms::Lambda<torch::data::Example<> >(
            [size](torch::data::Example<> example) {
                example.data = resize_tensor(example.data, size);
                return example;
            }
        );
    }

    torch::data::transforms::Lambda<torch::data::Example<> > pad(int size) {
        return torch::data::transforms::Lambda<torch::data::Example<> >(
            [size](torch::data::Example<> example) {
                example.data = pad_tensor(example.data, size);
                return example;
            }
        );
    }

    torch::data::transforms::Lambda<torch::data::Example<> > grayscale() {
        return torch::data::transforms::Lambda<torch::data::Example<> >(
            [](torch::data::Example<> example) {
                example.data = grayscale_image(example.data);
                return example;
            }
        );
    }

    torch::data::transforms::Lambda<torch::data::Example<> > normalize(double mean, double stddev) {
        return torch::data::transforms::Lambda<torch::data::Example<> >(
            [mean, stddev](torch::data::Example<> example) {
                example.data = example.data.to(torch::kFloat32).div(255);
                return example;
            }
        );
    }


    torch::data::transforms::Lambda<torch::data::Example<> > grayscaleToRGB() {
        return torch::data::transforms::Lambda<torch::data::Example<> >(
            [](torch::data::Example<> example) {
                example.data = grayscale_image(example.data);
                return example;
            }
        );
    }

    using TransformFunc = std::function<torch::Tensor(torch::Tensor)>;
    Compose::Compose() {

    }
    Compose::Compose(std::initializer_list<TransformFunc> transforms)
        : transforms(transforms) {
    }

    torch::Tensor Compose::operator()(torch::Tensor input) const {
        for (const auto &transform: this->transforms) {
            input = transform(std::move(input));
        }
        return input;
    }


    std::function<torch::Tensor(torch::Tensor input)> create_resize_transform(std::vector<int64_t> size) {
        auto resize_fn = [size](torch::Tensor img) -> torch::Tensor {
            img = img.unsqueeze(0); // Add batch dimension
            img = torch::nn::functional::interpolate(
                img,
                torch::nn::functional::InterpolateFuncOptions()
                    .size(std::vector<int64_t>({size[0], size[1]}))
                    .mode(torch::kBilinear)
                    .align_corners(false)
            );
            return img.squeeze(0); // Remove batch dimension
        };
        return resize_fn;
    }

}
