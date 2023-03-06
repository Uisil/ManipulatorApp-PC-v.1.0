#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&manager,&QNetworkAccessManager::authenticationRequired,this,&MainWindow::authenticationRequired);
    connect(&manager,&QNetworkAccessManager::encrypted,this,&MainWindow::encrypted);
    connect(&manager,&QNetworkAccessManager::preSharedKeyAuthenticationRequired,this,&MainWindow::preSharedKeyAuthenticationRequired);
    connect(&manager,&QNetworkAccessManager::proxyAuthenticationRequired,this,&MainWindow::proxyAuthenticationRequired);
    connect(&manager,&QNetworkAccessManager::sslErrors,this,&MainWindow::sslErrors);

    QByteArray data;

    data.append("asdasda");
    this->get("http://192.168.0.46/L");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::get(QString location)
{
    qInfo() << "Getting from server...";
    QNetworkReply* reply = manager.get(QNetworkRequest(location));
    connect(reply,&QNetworkReply::readyRead,this,&MainWindow::readyRead);
}

void MainWindow::post(QString location, QByteArray data)
{
    qInfo() << "Posting from server...";
    QNetworkRequest request = QNetworkRequest(QUrl(location));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"text/plain");

    QNetworkReply* reply = manager.post(request,data);
    connect(reply,&QNetworkReply::readyRead,this,&MainWindow::readyRead);
}

void MainWindow::readyRead()
{
 qInfo()<< "ReadReady";

 QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
 if(reply) reply->readAll();
}

void MainWindow::authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    qInfo()<< "autenticationRequired";
}

void MainWindow::encrypted(QNetworkReply *reply)
{
    qInfo()<< "encrypted";
}

void MainWindow::finished(QNetworkReply *reply)
{
    qInfo()<< "finished";
}

void MainWindow::preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator)
{
    qInfo()<< "predSharedKeyAuthenticationRequired";
}

void MainWindow::proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator)
{
    qInfo()<< "proxyAutehnticationRequired";
}

void MainWindow::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    qInfo()<< "sslErrors";
}

