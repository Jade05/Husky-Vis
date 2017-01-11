#include <iostream>
#include <vecotr>

#include "../core/common/util.hpp";

using namespace std;

int main() {

    // test sum
    std::vecotor<double> data1 = {10, 20, 30};
    cout << "sum: " << (Util.map_function("SUM"))(data1) << endl;

    // test count
    std::vecotor<double> data2 = {10, 20, 30};
    cout << "count: " << (Util.map_function("COUNT"))<double>(data1) << endl;

    // test mean
    std::vector<double> data3 = {10, 20, 30};
    cout << "mean: " << (Util.map_function("MEAN"))(data3) << endl;

    // test max 
    std::vecotr<double> data4 = {10, 20, 30};
    cout << "max: " << (Util.map_function("MAX"))(data4) << endl;

    // test min
    std::vecotr<double> data5 = {10, 20, 30};
    cout << "min: " << (Util.map_function("MIN"))(data5) << endl;

    // test variance
    std::vector<double> data6 = {10, 20, 30};
    cout << "variance" << (Util.map_function("VARIANCE"))(data6) << endl;
} 
