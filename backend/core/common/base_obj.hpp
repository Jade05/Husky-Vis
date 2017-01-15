#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace husky {
namespace visualization {

struct SuggestionKey {
    std::string measure;
    std::string dimension;
    std::string chart_type;
    std::string aggregate_type;
    std::string statistical_method;
};

class SuggestionObject {
   public:
    typedef husky::visualization::SuggestionKey KeyT;
    KeyT key;

    inline KeyT id() const { return key; }

    SuggestionObject() = default;
    explicit SuggestionObject(KeyT key) { this->key = key; }

    std::map<std::string, std::vector<double>> group_by_raw_data;
    std::map<std::string, double> aggregate_data;
    double score;
};

std::ostream& operator<<(std::ostream& stream, BaseObj& base_obj);

}
}

namespace std {

template <>
class hash<husky::visualization::BaseObj> {
    public:
        size_t operator()(const husky::visualization::BaseObj& obj) const; 
};

}

