/**
 * \class Game
 * \brief This class provides a interface of Game.  Game class has methods to
 *          set and get its information as well as to advance the game.
 */

#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <map>

#include "order.h"
#include "shipment.h"
#include "player.h"
#include "playerinterface.h"

class Order;
class PlayerInterface;

class Game
{
private:
    /**
    * \brief: ID of the game
    */
    int gId;
    /**
    * \brief: a map list to save the orders of all players in each week
    */
    std::map<int, std::vector<Order>> ordersToBeExecuted;
    /**
    * \brief: a map list to save the shipments of all players in each week
    */
    std::map<int, std::vector<Shipment>> shipmentsToBeExecuted;
    /**
    * \brief: a vector list of players in each week (frontend)
    */
    std::vector<PlayerInterface *> players;
    /**
     * \brief: This method sets consumer demand
     * \param cd consumer demand for week 
    */
    std::vector<int> demandPerWeek =
        {6, 6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
    /**
    * \brief: order delay
    */
    int orderDelay = 2;
    /**
    * \brief: holding cost with default value = 0.5
    */
    double holdingCost = 0.5;
    /**
    * \brief: backorder cost with default value = 1
    */
    double backorderCost = 1;
    /**
    * \brief: starting Inventory  with default value = 12
    */
    int startingInventory = 12;
    /**
    * \brief: totaly number of weeks in the game with default value = 26
    */
    int weeksToBePlayed = 26;
    /**
    * \brief: current week in the game
    */
    int currentWeek = 0;
    /**
    * \brief: totaly number of weeks in the game with default value = 26
    */
    int infoCode = 0;
    /**
    * \brief: the delay from the factory production with default value = 1
    */
    int factoryDelay = 1;
    /**
    * \brief: number of orders received
    */
    int nOrdersReceived = 0;
    /**
    * \brief: number of shipments received
    */
    int nShipmentsReceived = 0;
    /**
    * \brief: number of players received
    */
    int nPlayers = 5;
    /**
     * \brief: ID of the instructor
    */
    int instrid;
    /**
    * \brief: ID of the player Factory
    */
    int pFactId;
    /**
    * \brief: ID of the player Distributor
    */
    int pDistributorId;
    /**
    * \brief: ID of the player Factory
    */
    int pWholesalerId;
    /**
    * \brief: ID of the player Retailer
    */
    int pRetailerId;
    /**
    * \brief: shipment delay
    */
    int shipmentDelay;

    /**
    * \brief: total number of players in the game
    */
    int numberOfPlayers;
    /**
    * \brief: a vector list of players in each week
    */
    std::vector<Player *> player_players;
    /**
    * \brief: save the list of Consumer demand per week generated
    */
    std::vector<int> consumerDemandPerWeek;

public:
    /**
     * \brief constructor of the game
     */
    Game();

    /**
     * \brief Initializes a game based on supplied setters.
     * 
     * This method is to create orders and shipments based on the order delay. For instance, 
     * if the orderDelay is 2 weeks, orders and shipments for 
     * two weeks should be created. These values are either set 
     * by default or accessed using instructor. 
     */
    void initGame();

    /**
     * \brief This method is called by the instructor to start the game
     * 
     * To start executing 
     * orders and shipments for the 1st week
     */
    void startGame();

    /**
     * \brief Takes the order vector for the current week based on currentWeek proerty. Then loops through the vector and 
     * executes the orders by calling order.executeEvent() 
     */
    void executeOrdersForCurrentWeek();

    /**
     * \brief Calls the shipment vector for the current week 
     * based on currentWeek. 
     */
    void executeShipmentsForCurrentWeek();

    /**
     * \brief This method was listed in the initial documentation, but has been deprecated
     * 
     */
    void updatePlayerInventories();

    /**
     * \brief return the consumer order for the week given 
     * \return Consumer order for the week given.
     */
    int getConsumerOrderForWeek();

    /**
    * \brief Call executeOrderForCurrentWeek() 
    * and executeShipmentForCurrentWeek()
    */
    int advanceWeek();

    /**
     * \brief Add the parameter to the vector of orders
     * 
     * The order is placed in 
     * ordertoBeExecuted vector's correct location
     * 
     * \param numberOfBeers 
     * \param role
     */
    void addOrder(int numberOfBeers, int role);

    /**
     * \brief Add the parameter to the vector of shipments
     * 
     * \param numberOfBeers 
     * \param role
     */
    void addShipment(int numberOfBeers, int role);

    /**
     * \brief Adds a player pointer to the list of player
     * 
     * The order of players must
     *  be from downstream to upstream.
     */
    void addPlayerInterface(PlayerInterface *player);

    /**
     * \brief Get the pointer of the downstream player
     */
    PlayerInterface *getDownstream(int role);

    /**
     * \brief Get the pointer of the upstream player
     */
    PlayerInterface *getUpstream(int role);

    /**
     * \brief: This method sets the number of players
     * \param nop number of players
    */
    void setNumberOfPlayers(int nop);
    /**
     * \brief: This method gets the number of players
     * \return number of players
    */
    int getNumberOfPlayers();
    /**
     * \brief: check if the game is playable according to the parameters
     */
    bool isGamePlayable();
    /****************************************************************************************************/
    /***************************************** Setters & Getters *****************************************/

    /**
     * \brief: This method sets the Game id
     * \param gID game id
    */
    void setGId(int gID);
    /**
     * \brief: This method is to access orders for the current week
     * \param week
     */
    void setWeeksToBePlayed(int week);
    /**
     * \brief: This method sets the info code
     * \param code infoCode
    */
    void setInfoCode(int code);
    /**
     * \brief: This method sets the backorder cost in the game
     * \param cost backorder cost
    */
    void setBackorderCost(double cost);
    /**
     * \brief: This method sets the holding cost in the game
     * \param hc holding cost
    */
    void setHoldingCost(double hc);
    /**
     * \brief: This method sets the factory delay
     * \param delay factory delay
    */
    void setFactoryDelay(int delay);
    /**
     * \brief: This method sets the order delay
     * \param delay int delay
    */
    void setOrderDelay(int delay);
    /**
     * \brief: This method sets the starting inventory in the game
     * \param si starting inventory
    */
    void setStartingInventory(int si);

    /*
     * \brief: This method sets the current week 
     * \param week current week number
    */
    void setCurrentWeek(int week);
    /**
     * \brief: This method sets the shipment delay
     * \param delay int delay 
    */
    void setShipmentDelay(int delay);
    /**
     * \brief: This method gets the Game id
     * \return GId
    */
    int getGId();
    /**
     * \brief: This method gets the total number of weeks to be played
     * \return weeksToBePlayed 
    */
    int getWeeksToBePlayed();
    /**
     * \brief: This method sets the info code
     * \return infoCode
    */
    int getInfoCode();
    /**
     * \brief: This method gets the backorder cost in the game
     * \return backOrderCost 
    */
    double getBackorderCost();
    /**
     * \brief: This method gets the holding cost in the game
     * \return holdingCost
    */
    double getHoldingCost();
    /**
     * \brief: This method gets the factory delay
     * \return factoryDelay
    */
    int getFactoryDelay();
    /**
     * \brief: This method gets the order delay
     * \return orderDelay
    */
    int getOrderDelay();
    /**
     * \brief: This method gets the starting inventory in the game
     * \return startingInventory
    */
    int getStartingInventory();
    /**
     * \brief: This method sets the current week 
     * \return week current week number
    */
    int getCurrentWeek();
    /**
     * \brief: This method gets the shipment delay
     * \return  shipmentDelay
    */
    int getShipmentDelay();
    /**
     * \brief: This method sets the Instructor id
     * \param id instructor ID
    */
    void setInstrId(int id) { this->instrid = id; };
    /**
     * \brief: This method sets the player factory id
     * \param id player factory ID
    */
    void setPFactId(int id) { this->pFactId = id; };
    /**
     * \brief: This method sets the player distributor id
     * \param id player distributor id
    */
    void setPDistributorId(int id) { this->pDistributorId = id; };
    /**
     * \brief: This method gets the player distributor id
     * \param id player wholesaler id
    */
    void setPWholesalerId(int id) { this->pWholesalerId = id; };
    /**
     * \brief: This method sets the player retailer id
     * \param id
    */
    void setPRetailerId(int id) { this->pRetailerId = id; };

    /**
     * \brief: This method sets the Instructor id
     * \return instrID 
    */
    int getInstrId() { return this->instrid; };
    /**
     * \brief: This method gets the player distributor id
     * \return pFactId 
    */
    int getPFactId() { return this->pFactId; };
    /**
     * \brief: This method gets the player  distributorid
     * \return pDistributorId
    */
    int getPDistributorId() { return this->pDistributorId; };
    /**
     * \brief: This method sets the player wholesaler id
     * \return pWholesalerId 
    */
    int getPWholesalerId() { return this->pWholesalerId; };
    /**
     * \brief: This method gets the player retailer id
     * \return pRetailerId 
  */
    int getPRetailerId() { return this->pRetailerId; };
    /**
     * \brief: This vector is to generate passwords for the players and save
    */

    /**
     * \brief: This vector is to generate passwords for the players and save
    */
    std::vector<std::string> generatePasswords();
    /**
     * \brief: This method sets a vector of orders to be executed
     * \param ord map of orderlist with the week number
    */
    void setOrdersToBeExecuted(std::map<int, std::vector<Order>> ord);
    /**
     * \brief: This method gets a vector of orders to be executed
     * \return ordersToBeExecuted 
    */
    std::map<int, std::vector<Order>> getOrdersToBeExecuted();
    /**
     * \brief: This method sets a vector of orders to be executed
     * \param ship vector of shipments
    */
    void setShipmentsToBeExecuted(std::map<int, std::vector<Shipment>> ship);
    /**
     * \brief: This method gets a vector of orders to be executed
     * \return shipmentsToBeExecuted
    */
    std::map<int, std::vector<Shipment>> getShipmentsToBeExecuted();
    /**
     * \brief: This method sets a vector of players
     * \param ps player to be set
    */
    void setPlayers(std::vector<Player *> ps);
    /**
     * \brief: This method gets a vector of players
     * \return players 
    */
    std::vector<Player *> getPlayers();
    /**
     * \brief: This method sets consumer demand
     * \param cd consumer demand for week 
    */
    void setConsumerDemandPerWeek(std::vector<int> cd);
    /**
     * \brief: This method gets the number of players
     * \return consumerDemandPerWeek
    */
    std::vector<int> getConsumerDemandPerWeek();
      /**
     * \brief: This method is to add players sto the game
     * \param pla 
    */
  void addPlayer(Player * pla);
};

#endif //GAME_H
