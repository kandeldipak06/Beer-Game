#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>

#include "playerinterface.h"

class PlayerInterface;

/**
    * \class Player
    * \brief Features implemented for Player
*/
#define CONSUMER 0
#define RETAILER 1
#define WHOLESALER 2
#define DISTRIBUTOR 3
#define FACTORY 4

const std::string PLAYER_NAMES[] = {
    "Consumer",
    "Retailer",
    "Wholesaler",
    "Distributor",
    "Factory"};

class Player
{
private:
    /**
     * \brief ID of the player in the game
    */
    int pId;
    /**
     * \brief Role of the player (1=Retailer,2=Wholesaler,3=Distributor,4=Factory)
    */
    int role;
    /**
     * \brief Old Inventory of the player
    */
    int oldInventory;
    /**
     * \brief Old Backorder of the player
    */
    int oldBackOrder;
    /**
     * \brief Inventory of the player
    */
    int inventory = 12;
    /**
     * \brief Backorder of the player
    */
    int backOrder = 0;
    /**
     * \brief Incoming order from the downstream player
    */
    int incomingOrder = 0;
    /**
     * \brief Incoming shipment from the upstream player
    */
    int incomingShipment = 0;
    /**
     * \brief Outgoing shipment from the upstream player
    */
    int outgoingShipment = 0;
    /**
     * \brief Demand of the player
    */
    int demand;
    /**
     * \brief holding cost
     */
    double holdingCost = 0.5;
    /**
     * \brief backorder cost
     */
    double backOrderCost = 1;
    /**
     * \brief Total cost of the player during the game
    */
    double cost = 0;
    /**
     * \brief totalCost that the player has
    */
    double totalCost = 0;
    /**
     * \brief track if an order is received
    */
    bool orderReceived = false;
    /**
     * \brief track if a shipment is received
    */
    bool shipmentReceived = false;
    /**
     * \brief track if an order is placed
    */
    bool orderPlaced = false;
    /**
     * \brief track if a shipment is placed
    */
    bool shipmentPlaced = false;
    /**
     * \brief update data after each order or shipment
    */
    void updateData();
    /**
     * \brief PlayerInterface Object
    */
    PlayerInterface *playerInterface = nullptr;

public: // every function here has been made void just for making template, change it accordingly
    /**
     * \brief Constructor of Player
     */
    Player() {}
    /**
     * \brief Constructor of Player
     * \param role
     */
    Player(int role);
    /**
     * \brief setting Player Interface in the game
     */
    void setInterface(PlayerInterface *);
    /**
     * \brief This method gets available shipment
     * \param numberOfBeers to be subtracted from inventory
     * \returns available shipment
    */
    int getAvailableShipment(int numberOfBeers);
    /**
     * \brief This method places order
     * \param numBeer order to be placed
    */
    void placeOrder(int numBeer);
    /**
     * \brief This method places shipment
     * \param ship shipment to be placed
    */
    void placeShipment(int ship);
    /**
     * \brief This method gets incoming shipment
     * \returns incoming shipment
    */
    int getIncomingShipment();
    /**
     * \brief This method gets outgoing shipment
     * \returns outgoing shipment
    */
    int getOutgoingShipment();
    /**
     * \brief initialize the transcation of orders and shipments
     * \param nOrders
    */
    void startTransaction(int nOrders);
    /**
     * \brief check if both the order and shipments are received for the player
     * \returns orderReceived && shipmentReceived
    */
    bool transactionReceived();

    /**
     * \brief This method receive shipment
     * \param ship shipment to be received
    */
    void receiveShipment(int ship);
    /**
     * \brief This method receives order
     * \param order order to be received
    */
    void receiveOrder(int order);
    /**
     * \brief decreases inventory
     * \param numberOfBeers to decrease
     * \returns inventory decreased
    */
    int decreaseInventory(int numberOfBeers);
    /**
     * \brief increases inventory
     * \param numberOfBeers to decrease
     * \returns inventory decreased
    */
    int increaseInventory(int numberOfBeers);
    /**
     * \brief This method sets the player id
     * \param id player id
    */
    void setPId(int id);
    /**
     * \brief This method sets the demand for player
     * \param demand player's demand
    */
    void setDemand(int demand);
    /**
     * \brief This method sets the role of player
     * \param role player role
    */
    void setRole(int role);
    /**
     * \brief This method gets inventory
     * \param inv inventory
    */
    void setInventory(int inv);
    /**
     * \brief This method sets the backorder
     * \param backord backorder total
    */
    void setBackorder(int backord);
    /**
     * \brief This method sets outgoing shipment
     * \param ship outgoing shipment
    */
    void setOutgoingShipment(int ship);
    /**
     * \brief This method sets the order placed to either true or false
     * \param ordPlaced whether order was placed
    */
    void setOrderPlaced(int ordPlaced);
    /**
     * \brief This method sets the total cost
     * \param cost total cost
    */
    void setTotalCost(double cost);
    /**
     * \brief This method sets the incoming shipment
     * \param ship incoming shipment
    */
    void setIncomingShipment(int ship);
    /**
     * \brief This method sets cost
     * \param cost represents cost
    */
    void setCost(double cost);
    /**
     * \brief This method gets the player id
     * \returns id player id
    */
    int getPId();
    /**
     * \brief This method checks whether order was placed
     * \returns boolean value
    */
    bool isOrderPlaced();
    /**
     * \brief This method checks whether shipment was received
     * \returns boolean value
    */
    bool isShipmentPlaced();
    /**
     * \brief This method gets the role of player
     * \returns player role
    */
    int getRole() const { return role; };
    /**
     * \brief This method gets the backorder
     * \returns backorder
    */
    int getBackorder();
    /**
     * \brief This method gets the old backorder
     * \returns oldBackorder
    */
    int getOldBackOrder();
    /**
     * \brief This method gets the demand for player
     * \returns player's demand
    */
    int getDemand();
    /**
     * \brief This method gets cost
     * \returns cost
    */
    int getCost();
    /**
     * \brief This method gets the total cost
     * \returns total cost
    */
    int getTotalCost();
    /**
     * \brief This method gets inventory
     * \returns inventory
    */
    int getInventory();
    /**
     * \brief This method gets inventory
     * \returns oldInventory
    */
    int getOldInventory();
    /**
     * \brief This method sets the order received bool
     * \returns orderReceived
    */
    bool isOrderReceived();
    /**
     * \brief This method checks whether shipment was received
     * \returns shipmentReceived
    */
    bool isShipmentReceived();
};

#endif //PLAYER_H
