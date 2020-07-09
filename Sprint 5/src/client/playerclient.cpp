#include "playerclient.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <iostream>
PlayerClient::PlayerClient(QObject *parent)
    : QObject(parent), m_clientSocket(new QTcpSocket(this)), m_loggedIn(false)
{
    connect(m_clientSocket, &QTcpSocket::connected, this, &PlayerClient::connected);
    connect(m_clientSocket, &QTcpSocket::disconnected, this, &PlayerClient::disconnected);
    connect(m_clientSocket, &QTcpSocket::readyRead, this, &PlayerClient::onReadyRead);
    connect(m_clientSocket, &QTcpSocket::disconnected, this, [this]() -> void { m_loggedIn = false; });
}

void PlayerClient::login(const int &Gameid, const int &role)
{
    if (m_clientSocket->state() == QAbstractSocket::ConnectedState)
    {
        QDataStream clientStream(m_clientSocket);

        clientStream.setVersion(QDataStream::Qt_5_7);

        QJsonObject message;
        QJsonObject message1;
        message["type"] = QStringLiteral("login");
        message["role"] = role;
        message["game"] = Gameid;

        clientStream << QJsonDocument(message).toJson();
    }
}

void PlayerClient::sendMessage(const QString &text)
{
    if (text.isEmpty())
        return;
    QDataStream clientStream(m_clientSocket);

    clientStream.setVersion(QDataStream::Qt_5_7);

    QJsonObject message;
    message["type"] = QStringLiteral("message");
    message["numberOfBeers"] = text.toInt();
    qDebug() << text.toInt();
    beerlist.push_back(text.toInt());
    clientStream << QJsonDocument(message).toJson(QJsonDocument::Compact);
}

void PlayerClient::jsonReceived(const QJsonObject &docObj)
{
    std::cout << QString(QJsonDocument(docObj).toJson(QJsonDocument::Compact)).toStdString() << std::endl;

    const QJsonValue typeVal = docObj.value(QLatin1String("type"));

    if (typeVal.isNull() || !typeVal.isString())
        return;

    if (typeVal.toString().compare(QLatin1String("login"), Qt::CaseInsensitive) == 0)
    { 
        if (m_loggedIn)
            return;
        const QJsonValue resultVal = docObj.value(QLatin1String("success"));
        if (resultVal.isNull() || !resultVal.isBool())
            return;

        const bool loginSuccess = resultVal.toBool();
        if (loginSuccess)
        {

            playerName = docObj.value(QLatin1String("playerName")).toString();
            emit loggedIn();
            return;
        }

        const QJsonValue reasonVal = docObj.value(QLatin1String("reason"));
        emit loginError(reasonVal.toString());
    }
    else if (typeVal.toString().compare(QLatin1String("updateUi"), Qt::CaseInsensitive) == 0)
    {
        const QJsonArray senderVal = docObj["data"].toArray();
        for (QJsonValue x : senderVal)
        {
            QJsonObject j = x.toObject();
            const QJsonValue textVal = j.value(QLatin1String("value"));
            const QJsonValue text2Val = j.value(QLatin1String("data"));
            emit messageReceived(textVal.toString(), text2Val.toString());
        }
        return;
    }
    else if (typeVal.toString().compare(QLatin1String("newuser"), Qt::CaseInsensitive) == 0)
    { 
        const QJsonValue usernameVal = docObj.value(QLatin1String("username"));
        if (usernameVal.isNull() || !usernameVal.isString())
            return; // the username was invalid so we ignore
        // we notify of the new user via the userJoined signal
        emit userJoined(usernameVal.toString());
    }
    else if (typeVal.toString().compare(QLatin1String("userdisconnected"), Qt::CaseInsensitive) == 0)
    { 
        const QJsonValue usernameVal = docObj.value(QLatin1String("username"));
        if (usernameVal.isNull() || !usernameVal.isString())
            return; // the username was invalid so we ignore
        // we notify of the user disconnection the userLeft signal
        emit userLeft(usernameVal.toString());
    }
}

std::vector<int> PlayerClient::getBeerlist()
{
    //    beerlist.push_back(10);
    //    beerlist.push_back(15);
    //    beerlist.push_back(8);
    //    beerlist.push_back(13);
    //    beerlist.push_back(5);
    return beerlist;
}

void PlayerClient::setBeerlist(std::vector<int> &value)
{
    beerlist = value;
    // beerlist = {1,2,3,4,5};
}
void PlayerClient::disconnectFromHost()
{
    m_clientSocket->disconnectFromHost();
}
void PlayerClient::connectToServer(const QHostAddress &address, quint16 port)
{
    m_clientSocket->connectToHost(address, port);
}
//void PlayerClient::connected() {

//}
void PlayerClient::onReadyRead()
{

    QByteArray jsonData;
    
    QDataStream socketStream(m_clientSocket);
    
    socketStream.setVersion(QDataStream::Qt_5_7);
    
    int j = 0;
    for (;;)
    {
        // we start a transaction so we can revert to the previous state in case we try to read more data than is available on the socket
        socketStream.startTransaction();
        // we try to read the JSON data
        socketStream >> jsonData;
        std::cout << j++ << std::endl;
        std::cout << jsonData.toStdString() << std::endl;
        if (socketStream.commitTransaction())
        {
            
            QJsonParseError parseError;
           
            const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
            if (parseError.error == QJsonParseError::NoError)
            {
                
                if (jsonDoc.isObject())             
                    jsonReceived(jsonDoc.object());
            }
            
        }
        else
        {
            
            break;
        }
    }
}
