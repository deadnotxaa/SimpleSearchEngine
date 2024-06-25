#include "Index.hpp"

#include "google/protobuf/map.h"

deadnotxaa::Index::Index(std::string &common_path)
    : common_path_(std::move(common_path))
{}

void deadnotxaa::Index::CreateIndex() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    RecursiveScan(common_path_);
    CreateDocID();

    InvertedIndex index;

    for (auto& i : words_count_) {
        InvertedIndex::DocsList current_word_doc_list;

        for (auto& j : i.second) {
            InvertedIndex::DocsList::InfoPair current_pair;

            current_pair.set_doc_id(j.first);
            current_pair.set_word_occurrence_count(j.second);

            (*current_word_doc_list.add_docs_vector()) = current_pair;
        }

        (*index.mutable_index())[i.first] = current_word_doc_list;
    }

    // Output the contents
    for (const auto& item : index.index()) {
        std::cout << "Word: " << item.first << std::endl;
        for (const auto& doc : item.second.docs_vector()) {
            std::cout << "  Doc ID: " << doc.doc_id() << ", Word Occurrence Count: " << doc.word_occurrence_count() << std::endl;
        }
    }

    std::ofstream index_file("index.dat", std::ios::out | std::ios::binary | std::ios::trunc);
    if (!index.SerializeToOstream(&index_file)) {
        throw std::runtime_error("Inverted index wasn't saved due to unexpected problem!");
    }

    google::protobuf::ShutdownProtobufLibrary();
}

void deadnotxaa::Index::CreateDocID() {
    DocumentId documentId;

    std::size_t total_docs_length = 0;
    for (std::size_t i = 0; i < files_.size(); ++i) {
        std::size_t current_doc_length = SplitFile(files_[i], i);
        total_docs_length += current_doc_length;

        DocumentId::DocumentData currentDoc;
        currentDoc.set_document_name(files_[i]);
        currentDoc.set_document_length(current_doc_length);

        (*documentId.mutable_doc_id())[i] = currentDoc;
    }
    average_document_length_ = (total_docs_length / files_.size());

    std::ofstream doc_id_file("did.dat", std::ios::binary | std::ios::out | std::ios::trunc);
    if (!documentId.SerializeToOstream(&doc_id_file)) {
        throw std::runtime_error("Document IDs wasn't wrote due to unexpected problem");
    }
}

std::size_t deadnotxaa::Index::SplitFile(std::string& file_name, std::size_t file_number) {
    std::ifstream file(file_name, std::ios::in);
    std::size_t number_of_words = 0;

    std::string current_line;

    while (!file.eof()) {
        std::getline(file, current_line);
        std::vector<std::string> splitted_line;

        SplitString(current_line, splitted_line);

        number_of_words += splitted_line.size();

        for (auto& i : splitted_line) {
            if (!words_count_.contains(i)) {
                words_count_[i][file_number] = 0;
            }
            ++words_count_[i][file_number];
        }
    }

    return number_of_words;
}

void deadnotxaa::Index::FilterWord(std::string& word) {
    for (auto& i : word) {
        if (!isalpha(i) && !isdigit(i) && i != '_') {
            i = ' ';
        }
    }
}

void deadnotxaa::Index::SplitString(std::string& line, std::vector<std::string>& splitted_line) {
    FilterWord(line);

    // Erase all duplicated spaces
    for (std::size_t i = 0; i < line.size(); ++i) {
        if (line[i] != ' ') {
            break;
        }
        line.erase(line.begin() + i, line.begin() + i + 1);
        --i;
    }

    for (std::size_t i = 0; i < line.size(); ++i) {
        if (line[i] == ' ' && line[i - 1] == ' ') {
            line.erase(line.begin() + static_cast<int>(i), line.begin() + static_cast<int>(i) + 1);
        }
    }

    std::size_t pos;
    std::string token;
    std::string delimiter = " ";
    while ((pos = line.find(delimiter)) != std::string::npos) {
        token = line.substr(0, pos);
        if (!token.empty() && !std::all_of(token.begin(), token.end(), ::isdigit) ) {
            splitted_line.push_back(token);
        }
        line.erase(0, pos + delimiter.length());
    }

    if (!line.empty()) {
        splitted_line.push_back(line);
    }
}

void deadnotxaa::Index::RecursiveScan(const std::string& current_path) {
    for (const auto& file : std::filesystem::directory_iterator(current_path)) {
        try {
            if (std::filesystem::is_directory(file)) {
                RecursiveScan(file.path().string());
            } else {
                if (CheckExtension(file.path())) {
                    files_.push_back(file.path().string());
                }
            }
        } catch (std::filesystem::filesystem_error& error) {
            std::cerr << "WARNING! " << error.what() << std::endl;
        }
    }
}

bool deadnotxaa::Index::CheckExtension(const std::filesystem::path& path) {
    return path.extension() == ".cpp";
}
