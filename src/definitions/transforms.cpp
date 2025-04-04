#include "../../include/definitions/transforms.h"

namespace xt::data::transforms {
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


    torch::Tensor resize_tensor(const torch::Tensor &tensor, const std::vector<int64_t> &size) {
        return torch::nn::functional::interpolate(
            tensor.unsqueeze(0),
            torch::nn::functional::InterpolateFuncOptions().size(size).mode(torch::kBilinear).align_corners(false)
        ).squeeze(0);
    }

    torch::data::transforms::Lambda<torch::data::Example<> > resize(std::vector<int64_t> size) {
        return torch::data::transforms::Lambda<torch::data::Example<> >(
            [size](torch::data::Example<> example) {
                example.data = resize_tensor(example.data, size);
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


    /**
     * @brief Alias for a transformation function that takes a tensor and returns a tensor.
     *
     * This type alias defines a function signature for transformations that operate on
     * `torch::Tensor` objects, enabling flexible composition of operations within the Compose class.
     */
    using TransformFunc = std::function<torch::Tensor(torch::Tensor)>;

    /**
     * @brief Default constructor, initializing an empty transformation pipeline.
     *
     * Creates a Compose object with no transformations, allowing subsequent addition of transforms
     * if needed. The internal vector of transformations is default-initialized to empty.
     */
    Compose::Compose() {
    }

    /**
     * @brief Constructs a Compose object with a vector of transformation functions.
     * @param transforms A vector of TransformFunc objects specifying the sequence of transformations.
     *
     * Initializes the Compose object by storing the provided vector of transformation functions,
     * which will be applied in sequence when the object is called.
     */
    Compose::Compose(std::vector<TransformFunc> transforms)
        : transforms(transforms) {
    }

    /**
     * @brief Applies the sequence of transformations to the input tensor.
     * @param input The input tensor to be transformed.
     * @return A tensor resulting from applying all transformations in sequence.
     *
     * This function iterates over the stored transformations, applying each one to the input tensor
     * in the order they were provided. Each transformation’s output becomes the input to the next,
     * with the final result returned. The input tensor is moved into each transformation to optimize
     * performance by avoiding unnecessary copies where possible.
     */
    torch::Tensor Compose::operator()(torch::Tensor input) const {
        for (const auto &transform: this->transforms) {
            input = transform(std::move(input));
        }
        return input;
    }


    /**
     * @brief Converts a grayscale tensor to an RGB tensor.
     * @param tensor The input grayscale tensor, expected in format [N, H, W] or [N, 1, H, W].
     * @return A new tensor in RGB format [N, 3, H, W], with the grayscale values replicated across channels.
     *
     * This function transforms a grayscale tensor into an RGB tensor by ensuring the input has a channel
     * dimension and then replicating that channel three times to form RGB channels. If the input tensor
     * is 3D ([N, H, W]), it adds a channel dimension to make it [N, 1, H, W]. If it’s already 4D ([N, 1, H, W]),
     * it uses it as is. The `repeat` operation then duplicates the single channel into three, producing
     * an output tensor of shape [N, 3, H, W], where N is the batch size, H is height, and W is width.
     * This is useful for converting batched grayscale images to RGB format in LibTorch workflows.
     */
    torch::Tensor GrayscaleToRGB::operator()(const torch::Tensor &tensor) {
        torch::Tensor gray = tensor.dim() == 3 ? tensor.unsqueeze(1) : tensor; // Ensure [N, 1, H, W]
        return gray.repeat({1, 3, 1, 1}); // [N, 1, H, W] -> [N, 3, H, W]
    }


    /**
     * @brief Constructs a Resize object with the target size.
     * @param size A vector of 64-bit integers specifying the target dimensions (e.g., {height, width}).
     *
     * Initializes the Resize object by storing the provided size vector, which will be used
     * to resize input tensors in subsequent calls to the operator() function.
     */
    Resize::Resize(std::vector<int64_t> size) : size(size) {
    }

    /**
     * @brief Resizes the input tensor image to the target size using bilinear interpolation.
     * @param img The input tensor image to be resized, typically in format [C, H, W] (channels, height, width).
     * @return A new tensor with the resized dimensions, in format [C, H', W'] where H' and W' match the target size.
     *
     * This function applies bilinear interpolation to resize the input image tensor to the dimensions
     * specified in the constructor. It adds a batch dimension before interpolation (making the tensor
     * [1, C, H, W]), resizes it using torch::nn::functional::interpolate, and removes the batch dimension
     * afterward to return a tensor in the original format [C, H', W']. The interpolation is performed
     * with bilinear mode and align_corners set to false for smooth and standard resizing behavior.
     */
    torch::Tensor Resize::operator()(torch::Tensor img) {
        img = img.unsqueeze(0); // Add batch dimension
        img = torch::nn::functional::interpolate(
            img,
            torch::nn::functional::InterpolateFuncOptions()
            .size(std::vector<int64_t>({size[0], size[1]}))
            .mode(torch::kBilinear)
            .align_corners(false)
        );
        return img.squeeze(0); // Remove batch dimension
    }


    Pad::Pad(std::vector<int64_t> padding) : padding(padding) {
    }

    torch::Tensor Pad::operator()(torch::Tensor input) {
        return torch::nn::functional::pad(input, padding);
    }














}
