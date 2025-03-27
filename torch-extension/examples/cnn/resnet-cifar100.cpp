#include "includes/base.h"

#include "../../include/datasets/cifar.h"
#include "../../include/models/cnn/resnet.h"
#include "../../include/definitions/transforms.h"


using namespace std;
using Example = torch::data::Example<torch::Tensor, torch::Tensor>;

int main() {
    std::vector<int64_t> size = {224, 224};

    std::cout.precision(10);
    torch::Device device(torch::kCPU);

    auto dataset = xt::data::datasets::CIFAR100("/home/kami/Documents/temp/", DataMode::TRAIN, true);

    auto transformed_dataset = dataset
            .map(torch::ext::data::transforms::resize(size))
            .map(torch::ext::data::transforms::normalize(0.5, 0.5))
            .map(torch::data::transforms::Stack<>());

    auto train_loader = torch::data::make_data_loader<torch::data::samplers::SequentialSampler>(
        std::move(transformed_dataset), 64);

    torch::ext::models::ResNet model({ 3, 4, 6, 3},100, 3);
    model.to(device);
    model.train();
    torch::optim::Adam optimizer(model.parameters(), torch::optim::AdamOptions(1e-3));
    for (size_t epoch = 0; epoch != 10; ++epoch) {
        size_t batch_index = 0;
        auto train_loader_interator = train_loader->begin();
        auto train_loader_end = train_loader->end();
        while (train_loader_interator != train_loader_end) {
            torch::Tensor data, targets;
            auto batch = *train_loader_interator;
            data = batch.data;
            targets = batch.target;
            optimizer.zero_grad();
            torch::Tensor output;
            output = model.forward(data);
            torch::Tensor loss;
            loss = torch::nll_loss(output, targets);
            loss.backward();
            optimizer.step();
            if (++batch_index % 100 == 0) {
                std::cout << "Epoch: " << epoch << " | Batch: " << batch_index << " | Loss: " << loss.item<float>() <<
                        std::endl;
            }
            ++train_loader_interator;
        }
    }

    return 0;
}
