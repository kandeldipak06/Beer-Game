/** 
 * \class BeerGameServer
 * \brief This is the server side implementation for the game.
 */

#ifndef BEERGAMESERVER_H
#define BEERGAMESERVER_H

#include <QTcpSocket>
#include <QTcpServer>
#include <QWidget>
#include <QObject>
#include <vector>

#include "../playerinterface.h"
#include "../player.h"
#include "../game.h"

#include "playerinterfaceserver.h"

class PlayerInterfaceServer;
class Player;
class Game;

class BeerGameServer : public QTcpServer
{
    Q_OBJECT
    Q_DISABLE_COPY(BeerGameServer)
public:
    /**
     * \brief Constructor for BeerGameServer class 
     * \param parent
     */
    explicit BeerGameServer(QObject *parent = nullptr);

protected:
    /**
     * \brief accept incoming player clients
     * \param socketDescriptor
     */
    void incomingConnection(qintptr socketDescriptor) override;

signals:
    /**
     * \brief load messages by the server side 
     * \param msg
     */
    void logMessageServer(const QString &msg);

public slots:
    /**
     * \brief Stop the server
     */
    void stopServer();
    /**
     * \brief display log messages from the server
     * \param msg
     */
    void displayLogMessage(const QString &msg);

private slots:
    /**
     * \brief receiving JSON data from the player clients
     * \param sender
     * \param doc
     */
    void receiveJson(PlayerInterfaceServer *sender, const QJsonObject &doc);
    /**
     * \brief after a player client has left the game
     * \param sender
     */
    void playerDisconnected(PlayerInterfaceServer *sender);
    /**
     * \brief emit error messages to the server
     * \param sender
     */
    void playerError(PlayerInterfaceServer *sender);

private:
    /**
     * \brief send JSON data to the player clients
     * \param destination
     * \param message
     */
    void sendJson(PlayerInterfaceServer *destination, const QJsonObject &message);
    /**
     * \brief receive JSON data of the player client/s who logged out the game
     * \param sender
     * \param doc
     */
    void jsonFromLoggedOut(PlayerInterfaceServer *sender, const QJsonObject &doc);
    /**
     * \brief receive JSON data of the player client/s who logged in to the game
     * \param sender
     * \param doc
     */
    void jsonFromLoggedIn(PlayerInterfaceServer *sender, const QJsonObject &doc);

private:
    /**
     * \brief QVector of PlayerInterfaceServer clients
     */
    QVector<PlayerInterfaceServer *> m_clients;
    /**
     * \brief QVector of games
     */
    QVector<Game *> m_games;
    //        std::vector<Game *>* m_games = new std::vector<Game*>(10);
};

#endif // BEERGAMESERVER_H
