#include <iostream>
#include <vector>

#include "core/common/utils.hpp"

using namespace std;

int main() {

    std::cout << "map_function size: " << husky::visualization::Utils::map_function.size() << std::endl;
    
    // test sum
    std::vector<double> data1 = {10, 20 ,30};
    std::cout << "sum: " << (husky::visualization::Utils::map_function["SUM"])(data1) << std::endl;

    // test mean
    std::vector<double> data3 = {10, 20, 30};
    std::cout << "mean: " << (husky::visualization::Utils::map_function["MEAN"])(data3) << std::endl;

    // test max 
    std::vector<double> data4 = {10, 20, 30};
    std::cout << "max: " << (husky::visualization::Utils::map_function["MAX"])(data4) << std::endl;

    // test min
    std::vector<double> data5 = {10, 20, 30};
    std::cout << "min: " << (husky::visualization::Utils::map_function["MIN"])(data5) << std::endl;

    // test variance
    std::vector<double> data6 = {10, 20, 30};
    std::cout << "variance: " << (husky::visualization::Utils::map_function["VARIANCE"])(data6) << std::endl;

} 
