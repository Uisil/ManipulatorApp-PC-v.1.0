#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QDebug>
#include "webclient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    int valueZ1, valueZ2, valueZ3;
    bool gripperState;
    WebClient *webClient;


public slots:


private slots:

    void on_sliderZ1_valueChanged(int value);
    void on_sliderZ2_valueChanged(int value);
    void on_sliderZ3_valueChanged(int value);
};
#endif // MAINWINDOW_H
