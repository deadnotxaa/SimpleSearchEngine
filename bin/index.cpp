#include "lib/Index/Index.hpp"
#include "lib/QtGUI/IndexWindow.hpp"

#include <QApplication>

#include <string>

std::string ShowSelectionWindow(int argc, char** argv) {
    QApplication app(argc, argv);
    IndexWindow window;

    // Set transparency for window

    window.setAttribute(Qt::WA_TranslucentBackground, true);
    window.setStyleSheet("background: rgba(38, 35, 36, 0.3);"
                         "border-radius: 10px;"
                         "padding: 6px;");

    window.setFixedSize(1000, 500);
    window.setMaximumSize(1000, 500);

    window.show();

    QApplication::exec();
    return window.GetSelectedPath();
}

int main(int argc, char** argv) {
    // TODO: add extension choosing feature
    // TODO: Maybe create interface?

    std::string path = ShowSelectionWindow(argc, argv);

//    deadnotxaa::Index index(path);
//    index.CreateIndex();

//    std::ifstream did_in("did.dat", std::ios::in | std::ios::binary);
//    DocumentId did;
//
//    if (!did.ParseFromIstream(&did_in)) {
//        throw std::runtime_error("Document IDs loading failed");
//    }
//    std::vector<std::pair<uint64_t, std::string>> files;
//
//    for (auto& i : *did.mutable_doc_id()) {
//        files.emplace_back(i.second.document_length(), i.second.document_name());
//    }
//
//    std::sort(files.begin(), files.end());
//
//    for (auto& i : files) {
//        std::cout << i.first << " " << i.second << std::endl;
//    }

    return EXIT_SUCCESS;
}
