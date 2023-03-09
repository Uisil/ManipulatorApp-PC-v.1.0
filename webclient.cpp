#include "webclient.h"

WebClient::WebClient()
{
    connect(&manager,&QNetworkAccessManager::authenticationRequired,this,&WebClient::authenticationRequired);
    connect(&manager,&QNetworkAccessManager::encrypted,this,&WebClient::encrypted);
    connect(&manager,&QNetworkAccessManager::preSharedKeyAuthenticationRequired,this,&WebClient::preSharedKeyAuthenticationRequired);
    connect(&manager,&QNetworkAccessManager::proxyAuthenticationRequired,this,&WebClient::proxyAuthenticationRequired);
    connect(&manager,&QNetworkAccessManager::sslErrors,this,&WebClient::sslErrors);

    //QByteArray data;
    //data ="aasdasd\n"; //ZAWSZE NA KOŃCU '/n' ŻEBY SERVER WIEDZIAŁ ŻE TO KONIEC RAMKI DANYCH

    //this->post("http://192.168.0.46", data);
}

WebClient::~WebClient()
{

}

void WebClient::get(QString location)
{
    qInfo() << "Getting from server...";
    QNetworkReply* reply = manager.get(QNetworkRequest(location));
    connect(reply,&QNetworkReply::readyRead,this,&WebClient::readyRead);
}

void WebClient::post(QString location, QByteArray data)
{
    qInfo() << "Posting from server...";
    QNetworkRequest request = QNetworkRequest(QUrl(location));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"text/plain");

    QNetworkReply* reply = manager.post(request,data);
    connect(reply,&QNetworkReply::readyRead,this,&WebClient::readyRead);
}

void WebClient::readyRead()
{
 qInfo()<< "ReadReady";

 QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
 if(reply) reply->readAll();
}

void WebClient::authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    qInfo()<< "autenticationRequired";
}

void WebClient::encrypted(QNetworkReply *reply)
{
    qInfo()<< "encrypted";
}

void WebClient::finished(QNetworkReply *reply)
{
    qInfo()<< "finished";
}

void WebClient::preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator)
{
    qInfo()<< "predSharedKeyAuthenticationRequired";
}

void WebClient::proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator)
{
    qInfo()<< "proxyAutehnticationRequired";
}

void WebClient::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    qInfo()<< "sslErrors";
}
