#ifndef PLAYER_H
#define PLAYER_H

//#include "playerui.h"
#include <iostream>
#include <vector>
#include <memory>

class Game;

class Player
{
public:

    /**
     * \brief Constructor for Player class, sets the default values for player class
    */
    Player();

    /**
     * \brief distructor for player class
    */
    ~Player();


    /**
     * \brief Method to order shipment from upstream of the player
     * \param numberOfBeers is number of beers to be ordered
    */
    void placeOrder(int numberOfBeers);

    /**
     * \brief Method to ship a shipment to downstream of player
     * \param numberOfBeers is number of beers to be shipped
    */
    void placeShipment(int numberOfBeers);

    /**
     * \brief Method to get available no of beers to ship
     * \param n_demand is number of beers demanded
    */
    int getAvailableShipment(int n_demand);

    /**
     * \brief Method to receive Shipment
     * \param receivedBeers is number of beers to be received
    */
    void receiveShipment(int receivedBeers);

    /**
     * \brief Method to receive order from downstream of the player
     * \param orderedBeers is number of beers ordered to be received
    */
    void receiveOrder(int orderedBeers);

    /**
     * \brief Method to decrease inventory
     * \param numberOfBeers is number of beers to be decreased in the inventory
    */
    void decreaseInventory(int numberOfBeers);

    /**
     * \brief Method to increase inventory
     * \param numberOfBeers is number of beers to be increased in the inventory
    */
    void increaseInventory(int numberOfBeers);

    



    /**
     * \brief Setter method for the Player Id
     * \param n_PId setting value for player Id
    */
    void setPId(int n_PId){pId = n_PId;}

    /**
     * \brief Setter method for the Player role
     * \param n_role setting value for player role
    */
    void setRole(int n_role){role = n_role;}

    /**
     * \brief Setter method for the Player Inventory
     * \param n_inventory setting value for player inventory
    */
    void setInventory(int n_inventory){inventory = n_inventory;}

    /**
     * \brief Setter method for the Player's backorder
     * \param n_backorder setting value for player's backorder
    */
    void setBackorder(int n_backorder){backorder = n_backorder;}

    /**
     * \brief Setter method for the Player's incoming order
     * \param n setting value for player's incoming order
    */
    void setIncomingOrder(int n){incomingOrder = n;}

    /**
     * \brief Setter method for the Player's incoming Shipment
     * \param n setting value for player's incoming shipment
    */
    void setIncomingShipment(int n){incomingShipment = n;}

    /**
     * \brief Setter method for the Player's outgoing shipment
     * \param n setting value for player's outgoing shipment
    */
    void setOutgoingShipment(int n){outgoingShipment = n;}

    /**
     * \brief Setter method for the Player's cost
     * \param n_cost setting value for player's cost
    */
    void setCost(double n_cost){cost = n_cost;}

    /**
     * \brief Setter method for the Player's Total cost
     * \param n setting value for player's Total cost
    */
    void setTotalCost(double n){totalCost = n;}

    /**
     * \brief Setter method for shipmentReceived indicator
     * \param n setting value for player's shipmentReceived
    */
    void setOrderReceived(bool n){orderReceived = n;}

    /**
     * \brief Setter method for shipmentReceived indicator
     * \param n setting value for player's shipmentReceived
    */
    void setShipmentReceived(bool n){shipmentReceived = n;}

    /**
     * \brief Setter method for Order placed indicator
     * \param n setting value for player's OrderPlaced attribute
    */
    void setOrderPlaced(bool n){orderPlaced = n;}

    /**
     * \brief Setter method for shipment placed indicator
     * \param n setting value for player's shipmentPlaced attribute
    */
    void setShipmentPlaced(bool n){shipmentPlaced = n;}

    /**
     * \brief Setter method for the Players's demand
     * \param n_demand setting value for player's demand
    */
    void setDemand(int n_demand){demand = n_demand;}

    /**
     * \brief Setter method for the players game with which it is asociated
     * \param n_game setting value for game attribute
    */
    void setGame(Game* n_game){game = n_game;}




    /**
     * \brief Getter method for Player Id
     * \return Instructor Id
    */
    int getPId()const{return pId;}

    /**
     * \brief Getter method for Player's role in the game
     * \return role
    */
    int getRole()const{return role;}

    /**
     * \brief Getter method for player's inventory
     * \return player's inventory
    */
    int getInventory()const{return inventory;}

    /**
     * \brief Getter method for backorder cost
     * \return backorder cost
    */
    double getBackorder()const{return backorder;}

    /**
     * \brief Getter method for Incoming order
     * \return incomingOrder
    */
    int getIncomingOrder()const{return incomingOrder;}

    /**
     * \brief Getter method for Incoming shipment
     * \return incomingShipment
    */
    int getIncomingShipment()const{return incomingShipment;}

    /**
     * \brief Getter method for Outgoing shipment
     * \return outgoingShipment
    */
    int getOutgoingShipment()const{return outgoingShipment;}

    /**
     * \brief Getter method for player's cost
     * \return cost
    */
    double getCost()const{return cost;}

    /**
     * \brief Getter method for player's total cost
     * \return totalCost
    */
    double getTotalCost()const{return totalCost;}

    /**
     * \brief Getter method for player's indicator for order Received
     * \return orderReceived
    */
    bool getOrderReceived()const{return orderReceived;}

    /**
     * \brief Getter method for player's indicator for shipment Received
     * \return shipmentReceived
    */
    bool getShipmentReceived()const{return shipmentReceived;}

    /**
     * \brief Getter method for player's indicator for order Placed
     * \return orderPlaced
    */
    bool getOrderPlaced()const{return orderPlaced;}

    /**
     * \brief Getter method for player's indicator for shipment Placed
     * \return shipmentPlaced
    */
    bool getShipmentPlaced()const{return shipmentPlaced;}

    /**
     * \brief Getter method for demand of player
     * \return demand
    */
    int getDemand()const{return demand;}

    /**
     * \brief Getter method for the players associated game
     * \return game
    */
    Game* getGame()const{return game;}


private:
    /**
    * \brief Attribute for Player Id
    */
    int pId;

    /**
    * \brief Attribute for role of player in game
    */
    int role;

    /**
    * \brief Attribute for current inventory of the player
    */
    int inventory;

    /**
    * \brief Attribute for current backorder of the player
    */
    double backorder;

    /**
    * \brief Attribute for Incoming orders of number of beers for the player
    */
    int incomingOrder;

    /**
    * \brief Attribute for Incoming shipments of number of beers for the player
    */
    int incomingShipment;

    /**
    * \brief Attribute for Outgoing shipments of number of beers for the player
    */
    int outgoingShipment;

    /**
    * \brief Attribute for current cost of player in the game
    */
    double cost;

    /**
    * \brief Attribute for total cost of player in the game
    */
    double totalCost;

    /**
    * \brief Attribute signifing weather the player in account has received order or not
    */
    bool orderReceived;

    /**
    * \brief Attribute signifing weather the player in account has received shipment or not
    */
    bool shipmentReceived;

    /**
    * \brief Attribute signifing weather the player in account has placed order or not
    */
    bool orderPlaced;

    /**
    * \brief Attribute signifing weather the player in account has placed shipment or not
    */
    bool shipmentPlaced;

    /**
    * \brief Attribute for current demand of player in game
    */
    int demand;

    /**
    * \brief Attribute defining the game into which the player in account is involved
    */
    Game* game;

    /**
    * \brief Attribute the ui class with which the player instance is linked with
    */
    //Ui::PlayerUI *playerui;



};

#endif // PLAYER_H
