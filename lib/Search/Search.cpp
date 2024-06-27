#include "Search.hpp"

void deadnotxaa::getInvertedIndex(std::string& index_path, std::unordered_map<std::string, std::unordered_map<size_t, size_t>>& inverted_index) {
    InvertedIndex index;
    std::ifstream index_file(index_path, std::ios::binary | std::ios::in);

    if (!index.ParseFromIstream(&index_file)) {
        throw std::runtime_error("Can't load data from index due to unexpected problem");
    }

    for (auto& i : *index.mutable_index()) {
        std::unordered_map<std::size_t, std::size_t> current_map;
        for (auto& j : *i.second.mutable_docs_vector()) {
            current_map[j.doc_id()] = j.word_occurrence_count();
        }

        inverted_index[i.first] = current_map;
    }
}

void deadnotxaa::writeSearchResult(std::vector<std::pair<double, std::size_t>>& result) {
    std::ofstream output("out.txt", std::ios::out);
    std::ifstream did("did.dat", std::ios::in | std::ios::binary);

    DocumentId documentId;
    if (!documentId.ParseFromIstream(&did)) {
        throw std::runtime_error("Can't load data from document id due to unexpected problem");
    }

    std::sort(result.begin(), result.end());
    for (auto& i : result) {
        output << (*documentId.mutable_doc_id())[i.second].document_name() << std::endl;
    }
}
