
/**
 * \class ClientInterface
 * \brief User interface to connect to the server and start placing orders.
 *
 */

#ifndef CLIENTINTERFACE_H
#define CLIENTINTERFACE_H
#include <QWidget>
#include "playerclient.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
namespace Ui
{
class ClientInterface;
}
class ClientInterface : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ClientInterface)
public:
    /**
     * \brief ClientInterface constructor
     * \param parent
     */
    explicit ClientInterface(QWidget *parent = nullptr);
    /**
     * \brief ClientInterface constructor
     */
    ~ClientInterface();
private slots:
    /**
     * \brief show graph
     */ 
    void on_viewGraph_clicked();

private:
    /**
     * \brief ClientInterface UI sin the game
     */
    Ui::ClientInterface *ui;
    /**
     * \brief PlayerClient object
     */ 
    PlayerClient *m_PlayerClient;
    /**
     * \brief username of player
     */ 
    QString m_lastUserName;
private slots:
    /**
     * \brief Attempts to connect to the server
     * This function provides a user interface to connect to the
     * server by taking in the IP address and port numbers as input.
     *
     */
    void attemptConnection();

    /**
     * \brief Displays a dialog window to enter the role and gameId in
     * This function runs as soon as the connection to the server is established. It displays
     * a form dialog window for the user to enter the game ID and the role into. If the user enters
     * a valid game Id and role, the user can now place orders.
     */
    void connectedToServer();

    /**
     * \brief Sends login data to the server.
     * \param GameId: ID of the game that the user wants to connect to
     * \param role: role that the player wants to take in the game
     *
     */
    void attemptLogin(const int &GameId, const int &role);
    /**
     * \brief Sets the player role name once logged in to the game
    */
    void loggedIn();
    /**
     * \brief Show reason of Login failure
     * \param reason 
     *
     */

    void loginFailed(const QString &reason);

    /**
     * \brief Updates the user interface once the
     * message is received
     * \param sender the UI label to update
     * \param text The text to update the Ui label to
     */

    void messageReceived(const QString &sender, const QString &text);
    /**
     * \brief sends order message to the server
     */
    void sendMessage();
    /**
     * \brief Connection to the server is lost.
     *
     */
    void disconnectedFromServer();
};
#endif // CLIENTINTERFACE_H
