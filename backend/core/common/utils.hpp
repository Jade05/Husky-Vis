#pragma once 

#include <map>
#include <vector>
#include <math.h>
#include <functional>

namespace husky {
namespace visualization {

class Util {
public:

    /**
     * [SUM description]
     * @param {[type]} data [1, 2, 3, 4]
     */
    static double sum(std::vector<double> data) {
        double result = 0;

        for (auto elem : data) {
            result += elem;
        }

        return result;
    }

    static double mean(std::vector<double> data) {
        return sum(data) / data.size();
    }

    static double max(std::vector<double> data) {
        double max = data.at(0);

        for (auto elem : data) {
            if (elem > max) {
                max = elem;
            }
        }

        return max;
    }

    static double min(std::vector<double> data) {
        double min = data.at(0);

        for (auto elem : data) {
            if (elem < min) {
                min = elem;
            }
        }

        return min;
    }

    static double variance(std::vector<double> data) {
        double mean_value = mean(data);

        double sum = 0;
        for (auto elem : data) {
            sum += pow(elem - mean_value, 2);
        }

        return sum / data.size();
    }

    static std::map<std::string, std::function<double(std::vector<double>)>> map_function; 
};

}
}
