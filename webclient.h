#ifndef WEBCLIENT_H
#define WEBCLIENT_H

#include <QObject>
#include <QDebug>
#include <QIODevice>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QAuthenticator>
#include <QNetworkProxy>

class WebClient : public QObject
{
    Q_OBJECT

public:
    WebClient();
    ~WebClient();

private:
        QNetworkAccessManager manager;

public slots:
    void get(QString location);
    void post(QString location, QByteArray data);

private slots:
    void readyRead();
    void authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator);
    void encrypted(QNetworkReply *reply);
    void finished(QNetworkReply *reply);
    void preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator);
    void proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator);
    void sslErrors(QNetworkReply *reply, const QList<QSslError> &errors);
};

#endif // WEBCLIENT_H
