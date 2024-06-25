#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QPalette>
#include <QLabel>
#include <QColor>

class IndexWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit IndexWindow(QWidget *parent = nullptr);
    ~IndexWindow() override;

    std::string GetSelectedPath();

private slots:
    void browseFiles();
    void savePath();

private:
    QLineEdit *pathLineEdit;
    std::string path;
};

