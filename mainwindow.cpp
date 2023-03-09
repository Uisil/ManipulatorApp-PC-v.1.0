#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    webClient = new WebClient();
    location = "http://192.168.0.46";
    dataZ1.clear();
    dataZ2.clear();
    dataZ3.clear();
    dataZ1 = "\n";
    dataZ2 = "\n";
    dataZ3 = "\n";
}

MainWindow::~MainWindow()
{
    delete webClient;
    delete ui;
}

void MainWindow::on_sendButton_clicked()
{
    webClient ->post(location,dataZ1);
    webClient ->post(location,dataZ2);
    webClient ->post(location,dataZ3);
}


void MainWindow::on_sliderZ1_sliderMoved(int position)
{
    dataZ1.clear();
    dataZ1 += (uint8_t)position;
    dataZ1 += '\n';
}


void MainWindow::on_sliderZ2_sliderMoved(int position)
{
    dataZ2.clear();
    dataZ2 += (uint8_t)position;
    dataZ2 += '\n';
}


void MainWindow::on_sliderZ3_sliderMoved(int position)
{
    dataZ3.clear();
    dataZ3 += (uint8_t)position;
    dataZ3 += '\n';
}


void MainWindow::on_gripperOn_clicked()
{
    webClient ->post(location+"/gripper/ON","0\n");
}


void MainWindow::on_gripperOff_clicked()
{
    webClient ->post(location+"/gripper/OFF","1\n");
}

