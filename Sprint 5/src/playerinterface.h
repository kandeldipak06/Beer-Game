/** 
 * \class PlayerInterface
 * \brief Class for setting up the interface for players in Beer Game
 */

#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#include <QDialog>
#include <QJsonObject>
#include <QTcpSocket>

#include "game.h"
#include "player.h"

class Game;
class Player;

namespace Ui
{
class PlayerInterface;
}

class PlayerInterface : public QDialog
{
    Q_OBJECT

public:
    /**
     * \brief constructor of PlayerInterface
     * \param parent
     */
    explicit PlayerInterface(QWidget *parent = nullptr);
    /**
     * \brief constructor of PlayerInterface
     */
    ~PlayerInterface();
    /**
     * \brief receive order from the downstream player
     * \param numberOfBeers
     */
    virtual void receiveOrder(int numberOfBeers);
    /**
     * \brief receive shipment from the upstream player
     * \param numberOfBeers
     */
    virtual void receiveShipment(int numberOfBeers);
    /**
     * \brief place order to the upstream player
     * \param numberOfBeers
     */
    virtual void placeOrder(int numberOfBeers);
    /**
     * \brief place shipment to the downstream player
     * \param numberOfBeers
     */
    virtual void placeShipment(int numberOfBeers);
    /**
     * \brief update UI for player part
     */
    virtual void updateUi();
    /**
     * \brief sending orders to players and initiate the transaction
     * \param numberOfBeers
     */
    void sendOrderToPlayer(int numberOfBeers);
    /**
     * \brief setter of player in the game 
     * \param player
     */
    virtual void setPlayer(Player *player);
    /**
     * \brief setter game
     * \param game
     */
    virtual void setGame(Game *game);
    /**
     * \brief getter role of the player
     * \return role
     */
    virtual int getRole();
    /**
     * \brief getter of game
     * \return game
     */
    Game *getGame() { return game; };

protected:
    /**
     * \brief Player UI in the game
     */
    Ui::PlayerInterface *ui;
    /**
     * \brief Game object
     */
    Game *game = nullptr;
    /**
     * \brief player object
     */
    Player *player = nullptr;

private slots:
    /**
     * \brief features to be operated after clicking order button 
     */
    void on_orderBtn_clicked();
};

#endif // PLAYERINTERFACE_
