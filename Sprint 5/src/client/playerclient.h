/** 
 * \class PlayerClient
 * \brief This is the for direct communication of the player client with the 
 * server side implementation for the game.
 */

#ifndef PLAYERCLIENT_H
#define PLAYERCLIENT_H
#include <QDialog>
#include <QHostAddress>
#include <QTcpSocket>

class PlayerClient : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(PlayerClient)
public:
    /**
         * \brief PlayerClient object
         * \param parent
         */
    explicit PlayerClient(QObject *parent = nullptr);
    /**
     * \brief player name
     */ 
    QString playerName = "";
public slots:
    /**
         * \brief Connects to the server given the IP address and the port number.
         * \param address ip address of server
         * \param port port number
         */
    void connectToServer(const QHostAddress &address, quint16 port);
    /**
         * \brief Logs in to the game using valid game id and role
         * \param GameId id of the game to connect to
         * \param role  Game role
         */
    void login(const int &GameId, const int &role);
    /**
         * \brief send message to the server
         * sends message to the server in proper json format
         *
         */
    void sendMessage(const QString &text);
    /**
         * \brief disconnects from the host
         *
         */
    void disconnectFromHost();
    /**
     * \brief getter for beerlist
     */ 
    std::vector<int> getBeerlist();
    /**
     * \brief setter for beerlist
     * \param value
     */ 
    void setBeerlist(std::vector<int> &value);

private slots:
    /**
         * \brief This function is called when the socket receives data. Calls the jsonReceived
         * method for every QJSonObject.
         *
         */
    void onReadyRead();
signals:
    /**
         * \brief signals for different cases.
         *
         */

    void connected();
    /**
         * \brief send the JSON using QDataStream after logged in
         */
    void loggedIn();
    /**
         * \brief emit the login error reason
         * \param reason
         */
    void loginError(const QString &reason);
    /**
         * \brief features implemented after disconnected
         */
    void disconnected();
    /**
         * \brief emit game logic information to the server
         * \param sender
         * \param text
         */
    void messageReceived(const QString &sender, const QString &text);
    /**
         * \brief notify that a user has joined the game
         * \param username
         */
    void userJoined(const QString &username);
    /**
         * \brief notify that a user has left the game
         * \param username
         */
    void userLeft(const QString &username);

private:
    /**
         * \brief QTcpSocket for client
         */
    QTcpSocket *m_clientSocket;
    /**
         * \brief check if a user has logged in
         */
    bool m_loggedIn;
    /**
         * \brief pass the received JSON back to server and game logic
         * \param doc
         */
    void jsonReceived(const QJsonObject &doc);
    /**
     * \brief beerlist to show in the graph
     */ 
    std::vector<int> beerlist;
};

#endif // PLAYERCLIENT_H
