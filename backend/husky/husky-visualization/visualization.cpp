#include <string>
#include <vector>

#include "../core/engine.hpp"
#include "./core/dataloader/dataloader.hpp"

void visualization() {
    
} 

int main(int argc, char** argcv) {
    std::vector<std::string> args({
        "data",
        "data_schema",
        "distribute"
    });

    if (husky::init_with_args(argc, argv, args)) {
        husky::run_job(visualization);
        return 0;
    }
    return 1;
}
