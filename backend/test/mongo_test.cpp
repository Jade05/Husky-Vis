// Copyright 2016 Husky Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <set>
#include <string>
#include <utility>
#include <vector>

#include "boost/tokenizer.hpp"
#include "mongo/bson/bson.h"
#include "mongo/client/dbclient.h"

#include "husky/base/serialization.hpp"
#include "husky/core/engine.hpp"
#include "husky/io/input/inputformat_store.hpp"
#include "husky/lib/aggregator_factory.hpp"

class Word {
   public:
    using KeyT = std::string;

    Word() = default;
    explicit Word(const KeyT& w) : word(w) {}
    const KeyT& id() const { return word; }

    KeyT word;
    int count = 0;
};

bool operator<(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}

void wc() {
    auto& infmt = husky::io::InputFormatStore::create_mongodb_inputformat();
    infmt.set_server(husky::Context::get_param("mongo_server"));
    infmt.set_ns(husky::Context::get_param("mongo_db"), husky::Context::get_param("mongo_collection"));
    infmt.set_query("");

    auto& word_list = husky::ObjListStore::create_objlist<Word>();
    auto& ch = husky::ChannelStore::create_push_combined_channel<int, husky::SumCombiner<int>>(infmt, word_list);

    auto parse_wc = [&](std::string& chunk) {
        mongo::BSONObj o = mongo::fromjson(chunk);
        ch.push(1, chunk);
    };

    husky::load(infmt, parse_wc);

    husky::list_execute(word_list, [&ch](Word& word) {
         husky::LOG_I << word.id();
    });

}

int main(int argc, char** argv) {
    std::vector<std::string> args;
    args.push_back("mongo_server");
    args.push_back("mongo_db");
    args.push_back("mongo_collection");
    if (husky::init_with_args(argc, argv, args)) {
        husky::LOG_I << "before run job";
        husky::run_job(wc);
        return 0;
    }
    return 1;
}
