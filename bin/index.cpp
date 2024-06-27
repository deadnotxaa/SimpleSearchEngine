#include "lib/QtGUI/IndexWindow.hpp"

#include <QApplication>

#include <string>

void ShowSelectionWindow(int argc, char** argv) {
    QApplication app(argc, argv);
    IndexWindow window;

    // Set transparency for window
    window.setStyleSheet("background: rgb(255, 255, 255);"
                         "border-radius: 10px;"
                         "padding: 6px;");

    window.setMinimumSize(300, 200);
    window.show();

    QApplication::exec();
}

int main(int argc, char** argv) {

    ShowSelectionWindow(argc, argv);

    return EXIT_SUCCESS;
}
