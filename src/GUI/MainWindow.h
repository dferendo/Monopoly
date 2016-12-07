//
// Created by dylan on 06/12/2016.
//

#ifndef MONOPOLY_MAINWINDOW_H
#define MONOPOLY_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

namespace GUI {
    class MainWindow : public QMainWindow {
    Q_OBJECT
    private:
        Ui::MainWindow *ui;
    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
    };
}

#endif //MONOPOLY_MAINWINDOW_H
