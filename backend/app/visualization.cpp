#include <iostream>

#include <string>
#include <vector>

#include "husky/core/engine.hpp"

#include "preprocess.hpp"
#include "core/dataloader/dataloader.hpp"

using namespace std;

void visualization() {
  // distributed suggestions
  const std::string& distributed = husky::Context::get_param("distribute");
  if (distributed == "suggestions") {
    // default strategy: suggestions loaded balance in each worker and each thread

  } else if (distributed == "data") {
    // override
  }
}

int main(int argc, char** argv) {
    std::vector<std::string> args({
        "data",
        "data_schema",
        "distribute",
        "topk"
    });

    if (husky::init_with_args(argc, argv, args)) {
        husky::run_job(visualization);
        return 0;
    }
    return 1;
}
