//
// Created by dylan on 06/12/2016.
//

#include "MainWindow.h"
#include "../forms/ui_mainwindow.h"
#include <QStyle>
#include <QDesktopWidget>

GUI::MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    // Build the actual window found in the forms
    ui->setupUi(this);
    // Set window Title
    this->setWindowTitle("MonOOPoly");
    // Set window to center
//    this->setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, this->size(), qApp->desktop()->availableGeometry()));
}

GUI::MainWindow::~MainWindow() {
    delete ui;
}