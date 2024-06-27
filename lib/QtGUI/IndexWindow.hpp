#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QPalette>
#include <QLabel>
#include <QColor>
#include <QLayout>

#include "../Index/Index.hpp"
#include "../Parser/Parser.hpp"
#include "../Search/Search.hpp"


class IndexWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit IndexWindow(QWidget *parent = nullptr);
    ~IndexWindow() override;


private slots:
    void browseFiles();
    void browseIndex();

    void createIndex();
    void search();

private:
    std::string path;
    std::string selected_index_path;
    std::string query;
};

