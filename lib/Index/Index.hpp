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
    class Index {
    public:
        explicit Index(std::string&);

        void CreateIndex();

    private:

        std::size_t SplitFile(std::string&, std::size_t);
        void CreateDocID();

        static void FilterWord(std::string&);
        void SplitString(std::string&, std::vector<std::string>&);
        void RecursiveScan(const std::string&);
        bool CheckExtension(const std::filesystem::path&);

        std::size_t average_document_length_{}; // avg.d.l.

        std::string common_path_;
        std::vector<std::string> files_{};
        std::unordered_set<std::string> extensions_;
        std::unordered_map<std::string, std::unordered_map<std::size_t, std::size_t>> words_count_;
    };
} // deadnotxaa
