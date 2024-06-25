#include "IndexWindow.hpp"

IndexWindow::IndexWindow(QWidget *parent)
        : QMainWindow(parent)
{
    auto *centralWidget = new QWidget(this);
    auto *layout = new QVBoxLayout();
    auto *buttonsLayout = new QHBoxLayout();

    // Label upon all elements
    auto *text = new QLabel("Welcome to this piece of shit.");
    text->setStyleSheet("font: 50px;"
                        "color: black;");
    text->setAlignment(Qt::AlignCenter);
    text->setMargin(0);
    text->setMaximumHeight(70);
    text->setAttribute(Qt::WA_TranslucentBackground, true);

    // Adding line for choosing path using internal filesystem
    pathLineEdit = new QLineEdit(this);
    pathLineEdit->setStyleSheet("border-radius: 10px; padding: 6px;"
                                "background-color: rgba(230, 230, 230, 0.7);"
                                "color: black;");
    pathLineEdit->setAttribute(Qt::WA_TranslucentBackground, true);

    // Creating buttons
    auto *browseButton = new QPushButton("Select Path", this);
    auto *confirmButton = new QPushButton("Confirm Choice", this);

    // Set buttons style
    browseButton->setStyleSheet("background-color: rgba(99, 199, 86, 0.7);"
                                 "border-radius: 10px; padding: 6px;"
                                 "color: black;");

    confirmButton->setStyleSheet("background-color: rgba(237, 106, 94, 0.7);"
                                 "border-radius: 10px; padding: 6px;"
                                 "color: black;");

    // Adding buttons in a row
    buttonsLayout->addWidget(browseButton);
    buttonsLayout->addWidget(confirmButton);

    // Adding all widgets to main layout
    layout->addWidget(text);
    layout->addWidget(pathLineEdit);
    layout->addLayout(buttonsLayout);

    // Connecting slots
    connect(browseButton, &QPushButton::clicked, this, &IndexWindow::browseFiles);
    connect(confirmButton, &QPushButton::clicked, this, &IndexWindow::savePath);

    centralWidget->setLayout(layout);
    centralWidget->setFixedSize(1000, 500);
    centralWidget->setMaximumSize(1000, 500);
    setCentralWidget(centralWidget);
}

IndexWindow::~IndexWindow() = default;

void IndexWindow::browseFiles() {
    QString filePath = QFileDialog::getExistingDirectory(this, "Choose Path", "");
    if (!filePath.isEmpty()) {
        pathLineEdit->setText(filePath);
    }
}

void IndexWindow::savePath() {
    path = pathLineEdit->text().toUtf8().data();
    if (!path.empty()) {
        this->close();
    }
}

std::string IndexWindow::GetSelectedPath() {
    return path;
}
