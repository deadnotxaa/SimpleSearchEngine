#pragma once

#include <.pb.h>

#include <string>
#include <filesystem>
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <cinttypes>

namespace deadnotxaa {
    void getInvertedIndex(std::string&, std::unordered_map<std::string, std::unordered_map<std::size_t, std::size_t>>&);
    void writeSearchResult(std::vector<std::pair<double, std::size_t>>&);

}
