#include <iostream>
#include <QApplication>
#include "Monopoly.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    srand (time(NULL));
    Monopoly test;
    test.start();
    return 0;
}