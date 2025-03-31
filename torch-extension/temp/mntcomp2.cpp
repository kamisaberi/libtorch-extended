#include <torch/torch.h>
#include <torch/data/datasets/mnist.h>
#include <iostream>
#include <vector>
#include "../include/datasets/mnist.h"
#include "../include/models/cnn/lenet5.h"
#include <torch/data/transforms/base.h>
#include <functional>
#include "../include/definitions/transforms.h"

#include "../include/datasets/mnist.h"
#include "../include/models/cnn/lenet5.h"
#include "../include/definitions/transforms.h"
#include "../include/data-loaders/data-loader.h"
#include "../include/trainers/trainer.h"

using namespace std;
using Example = torch::data::Example<torch::Tensor, torch::Tensor>;

int main() {
    std::vector<int64_t> size = {32, 32};
    std::cout.precision(10);
    torch::Device device(torch::kCPU);

    auto dataset = xt::data::datasets::MNIST("/home/kami/Documents/temp/", DataMode::TRAIN, true,
                                             {
                                                 xt::data::transforms::create_resize_transform(size),
                                                 torch::data::transforms::Normalize<>(0.5, 0.5)
                                             });
    auto transformed_dataset =  dataset.map(torch::data::transforms::Stack<>());

    xt::DataLoader<decltype(transformed_dataset)> loader(std::move(transformed_dataset), torch::data::DataLoaderOptions().batch_size(64).drop_last(false), /*shuffle=*/true);
//    xt::DataLoader<decltype(dataset)> loader(std::move(dataset), torch::data::DataLoaderOptions().batch_size(64).drop_last(false), /*shuffle=*/true);



    xt::models::LeNet5 model(10);
    model.to(device);
    model.train();
    torch::optim::Adam optimizer(model.parameters(), torch::optim::AdamOptions(1e-3));
    xt::Trainer trainer;
    trainer.setOptimizer(&optimizer)
        .setMaxEpochs(5)
        .setLossFn([](auto output, auto target) {return torch::nll_loss(output, target);});
//    trainer.set

    trainer.fit<decltype(transformed_dataset)>(&model ,loader );

//    for (size_t epoch = 0; epoch != 10; ++epoch) {
//        cout << "epoch: " << epoch << endl;
//        for (auto& batch : loader) {
//
//            torch::Tensor data, targets;
//            data = batch.data;
//            targets = batch.target;
//            optimizer.zero_grad();
//            torch::Tensor output;
//            output = model.forward(data);
//            torch::Tensor loss;
//            loss = torch::nll_loss(output, targets);
//            loss.backward();
//            optimizer.step();
//            //                std::cout << "Epoch: " << epoch << " | Batch: " <<  " | Loss: " << loss.item<float>() <<                            std::endl;
//
//            //            }
//
//        }
//    }
    return 0;
}
