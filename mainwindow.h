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
    QString location;
    QByteArray dataZ1;
    QByteArray dataZ2;
    QByteArray dataZ3;


public slots:


private slots:
    void on_sendButton_clicked();
    void on_sliderZ1_sliderMoved(int position);
    void on_sliderZ2_sliderMoved(int position);
    void on_sliderZ3_sliderMoved(int position);
    void on_gripperOn_clicked();
    void on_gripperOff_clicked();
};
#endif // MAINWINDOW_H
