#pragma once

#include <torch/torch.h>
#include "../exceptions/implementation.h"


namespace torch::ext::data::datasets {
   class LFWPeople : torch::data::Dataset<LFWPeople> {

    public :
       LFWPeople();
    };
   class LFWPairs : torch::data::Dataset<LFWPairs> {

    public :
       LFWPairs();
    };
}
