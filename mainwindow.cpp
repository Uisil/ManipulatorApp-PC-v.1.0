#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    webClient = new WebClient();


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_sliderZ1_valueChanged(int value)
{
    valueZ1 = value;
}


void MainWindow::on_sliderZ2_valueChanged(int value)
{
    valueZ2 = value;
}


void MainWindow::on_sliderZ3_valueChanged(int value)
{
    valueZ3 = value;
}

