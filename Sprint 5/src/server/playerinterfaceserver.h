/** 
 * \class PlayerInterfaceServer
 * \brief Class for setting up sockets for players in Beer Game
 */

#ifndef PLAYERINTERFACESERVER_H
#define PLAYERINTERFACESERVER_H

#include <QTcpSocket>
#include <QWidget>

#include "../playerinterface.h"
#include "../player.h"

class Player;

class PlayerInterfaceServer : public PlayerInterface
{
    Q_OBJECT
public:
    /**
     * \brief constructor of PlayerInterfaceServer
     * \param parent
     */
    explicit PlayerInterfaceServer(QWidget *parent = nullptr);
    /**
     * \brief setting up socket 
     * \param socketDescriptor
     */
    virtual bool setSocketDescriptor(qintptr socketDescriptor);
    /**
     * \brief sending JSON data related to the game logic
     * \param jsonData
     */
    void sendJson(const QJsonObject &jsonData);
    /**
     * \brief set role in the game
     */
    void setRole(int role);
    /**
     * \brief update UI of the game
     */
    void updateUi() override;

signals:
    /**
     * \brief update UI of the game
     * \param jsonDoc
     */
    void jsonReceived(const QJsonObject &jsonDoc);
    /**
     * \brief disconnect from Player
     */
    void disconnectedFromPlayer();
    /**
     * \brief show error messages
     */
    void error();
    /**
     * \brief messages related to client player
     * \param msg
     */
    void logMessagePlayer(const QString &msg);

public slots:
    /**
     * \brief disconnect the player from the game
     */
    void disconnectFromPlayer();

private slots:
    /**
     * \brief receive json
     */
    void receiveJson();

private:
    /**
     * \brief TCP socket variable to connect players to the game
     */
    QTcpSocket *m_playerSocket;
};

#endif // PLAYERINTERFACESERVER_H
