#include "IndexWindow.hpp"

#include <iostream>

IndexWindow::IndexWindow(QWidget *parent)
        : QMainWindow(parent)
{
    auto *centralWidget = new QWidget(this);

    auto *layout = new QHBoxLayout();
    auto *index_layout = new QVBoxLayout();
    auto *search_layout = new QVBoxLayout();

    auto *index_label = new QLabel("Create index");
    index_label->setStyleSheet("color: black");
    index_label->setAlignment(Qt::AlignHCenter);

    auto *search_label = new QLabel("Select index and search");
    search_label->setStyleSheet("color: black");
    search_label->setAlignment(Qt::AlignHCenter);

    layout->addLayout(index_layout);
    layout->addLayout(search_layout);

    auto *choose_path_button = new QPushButton("Select path to index");
    auto *create_index = new QPushButton("Create index");

    auto *choose_index = new QPushButton("Choose index to search");

    auto *query_field = new QLineEdit();
    query_field->setPlaceholderText("Type your query");

    auto *save_query = new QPushButton("Save query");

    auto *search_button = new QPushButton("Search!");

    index_layout->addWidget(index_label);
    index_layout->addWidget(choose_path_button);
    index_layout->addWidget(create_index);

    search_layout->addWidget(search_label);
    search_layout->addWidget(choose_index);
    search_layout->addWidget(query_field);
    search_layout->addWidget(save_query);
    search_layout->addWidget(search_button);


    choose_path_button->setStyleSheet("background-color: rgb(99, 199, 86);"
                                      "border-radius: 10px; padding: 6px;"
                                      "color: white;");

    create_index->setStyleSheet("background-color: rgb(41, 96, 197);"
                                "border-radius: 10px; padding: 6px;"
                                "color: white;");

    choose_index->setStyleSheet("background-color: rgb(99, 199, 86);"
                                "border-radius: 10px; padding: 6px;"
                                "color: white;");

    save_query->setStyleSheet("background-color: rgb(99, 199, 86);"
                                "border-radius: 10px; padding: 6px;"
                                "color: white;");

    search_button->setStyleSheet("background-color: rgb(41, 96, 197);"
                                "border-radius: 10px; padding: 6px;"
                                "color: white;");


    query_field->setStyleSheet("border-radius: 10px; padding: 6px;"
                               "color: white;"
                               "background-color: rgb(30, 30, 30);");


    connect(choose_path_button, &QPushButton::clicked, this, &IndexWindow::browseFiles);
    connect(create_index, &QPushButton::clicked, this, &IndexWindow::createIndex);
    connect(choose_index, &QPushButton::clicked, this, &IndexWindow::browseIndex);
    connect(search_button, &QPushButton::clicked, this, &IndexWindow::search);
    connect(save_query, &QPushButton::clicked, this, [=, this]() {query = query_field->text().toStdString();});


    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}
// 41 96 197
IndexWindow::~IndexWindow() = default;

void IndexWindow::browseFiles() {
    QString filePath = QFileDialog::getExistingDirectory(this, "Choose Path", "");
    if (!filePath.isEmpty()) {
        path = filePath.toStdString();
    }
}

void IndexWindow::browseIndex() {
    QString filePath = QFileDialog::getOpenFileName(this, "Choose Path", "");
    if (!filePath.isEmpty()) {
        selected_index_path = filePath.toStdString();
    }
}

void IndexWindow::createIndex() {
    deadnotxaa::Index index(path);
    index.CreateIndex();
}

std::vector<std::string> SplitString(const std::string& str) {
    std::istringstream iss(str);

    return {std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>()};
}

void IndexWindow::search() {
    std::unordered_map<std::string, std::unordered_map<std::size_t, std::size_t>> inverted_index;
    std::vector<std::string> query_vec = SplitString(query);

    deadnotxaa::getInvertedIndex(selected_index_path, inverted_index);
    deadnotxaa::QueryHandler handler(query_vec, inverted_index);
    handler.HandleQuery();

    std::ofstream output("out.txt", std::ios::out);
    std::ifstream did("did.dat", std::ios::in | std::ios::binary);
    std::ifstream info_file("index_info.dat", std::ios::in | std::ios::binary);

    DocumentId documentId;
    if (!documentId.ParseFromIstream(&did)) {
        throw std::runtime_error("Can't load data from document id due to unexpected problem");
    }

    GeneralInformation info;
    if (!info.ParseFromIstream(&info_file)) {
        throw std::runtime_error("Can't load data from general info due to unexpected problem");
    }

    std::unordered_map<std::size_t, double> scores;
    std::size_t average_document_length = info.average_document_length();
    std::size_t total_documents_length = info.total_documents_length();
    double b = info.b_coefficient();
    double k1 = info.k1_coefficient();

    std::vector<std::pair<double, std::size_t>> answer;

    for (auto& i : handler.GetIndices()) {
        std::size_t doc_len = (*documentId.mutable_doc_id())[i].document_length();
        std::size_t nq = handler.GetIndices().size();

        double idf = std::log((static_cast<double>(total_documents_length) - static_cast<double>(nq) + 0.5) / (static_cast<double>(nq) + 0.5) + 1);
        double score = 0;

        for (auto& j : handler.GetTerms()) {
            std::size_t func = inverted_index[j][i]; // word occ. cnt.
            double part_score = idf * (func * (k1 + 1)) / (func + k1 * (1 - b + b * doc_len / average_document_length));
            score += part_score;
        }

        answer.emplace_back(i, score);
    }

    deadnotxaa::writeSearchResult(answer);

    this->close();
}
