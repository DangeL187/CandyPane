#include "Application.hpp"

int main(int argc, char* argv[]) {
    //setlocale(LC_ALL, "Russian");

    Application app(argc, argv);

    return QApplication::exec();
}