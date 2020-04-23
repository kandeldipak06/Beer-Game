#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <memory>
#include <map>
#include <vector>
//#include "include/player.h"
//#include "include/shipment.h"
//#include "include/order.h"
class Player;
class Shipment;
class Order;
class QWidget;


class Game
{
public:
    /**
     * \brief Constructor for game class, sets the default values for game class
    */
    Game();

    /**
     * \brief distructor for game class
    */
    ~Game();
    

    /**
     * \brief Method to start the game
     * \par parent is the pointer to the parent widget
    */
    void startGame();

    /**
     * \brief Method to execute orders for current week
    */
    void executeOrdersForCurrentWeek();

    /**
     * \brief Method to execute shipments for current week
    */
    void executeShipmentsForCurrentWeek();

    /**
     * \brief Method to update player inventories
    */
    void updatePlayerInventories();

    /**
     * \brief Method to get costumer order for the week
     * \param week is the week for which the order is requested
    */
    int getConsumerOrderForWeek(int week);

    /**
     * \brief Method advance a week during the game
    */
    void advanceWeek();

    /**
     * \brief Method to add order
     * \param role defines the plyer to be targeted
     * \param numberOfBeers defines the number of beers to be added in the order
    */
    void addOrder(const int& role, int numberOfBeers);

    /**
     * \brief Method to add order
     * \param role defines the plyer to be targeted
     * \param numberOfBeers defines the number of beers to be added in the shipment
    */
    void addShipment(const int& role, int numberOfBeers);

    /**
     * \brief Method to add player in the game
     * \param player defines the plyer to be added
    */
    void addPlayer(Player* new_player);

    /**
     * \brief Method to get the the downstream player for a role in the game
     * \param role defines the role of the player in account
    */
    Player* getDownstream(const int& role);

    /**
     * \brief Method to get the the Upstream player for a role in the game
     * \param role defines the role of the player in account
    */
    Player* getUpstream(const int& role);

    /**
     * \brief Method to generate password for the game
    */
    std::vector<std::string> generatePasswords();



    /**
     * \brief Setter method for the Game Id
     * \param n_id setting value Game Id
    */
    void setGId(int n_id);

    /**
     * \brief Setter method for the Instructor Id
     * \param n_id setting value for Instructor Id
    */
    void setInstrId(int n_id);

    /**
     * \brief Setter method for the Factory Id
     * \param n_id setting value for Factory Id
    */
    void setPFactId(int n_id);

    /**
     * \brief Setter method for the Distributor Id
     * \param n_id setting value for Distributor Id
    */
    void setPDistributorId(int n_id);

    /**
     * \brief Setter method for the Wholesaler Id
     * \param n_id setting value for Wholesaler Id
    */
    void setPWholesalerId(int n_id);

    /**
     * \brief Setter method for the Retailer Id
     * \param n_id setting value for Retailer Id
    */
    void setPRetailerId(int n_id);

    /**
     * \brief Setter method for the Consumer demand per week
     * \param v setting value for consumer demand per week
    */
    void setConsumerDemandPerWeek(std::shared_ptr<std::vector<int>> v){consumerDemandPerWeek = *v;}

    /**
     * \brief Setter method for the Order Time delay
     * \param n_id setting value for Order delay
    */
    void setOrderDelay(int n);

    /**
     * \brief Setter method for the Shipment delay
     * \param n setting value for shipment delay
    */
    void setShipmentDelay(int n);

    /**
     * \brief Setter method for the Holding cost
     * \param n setting value for Holding cost
    */
    void setHoldingCost(double n);

    /**
     * \brief Setter method for Backorder cost
     * \param n setting value for Backorder cost
    */
    void setBackorderCost(double n);

    /**
     * \brief Setter method for the Starting inventory
     * \param n setting value for starting inventory
    */
    void setStartingInventory(int n);

    /**
     * \brief Setter method for Weeks to be played
     * \param n setting value for Weeks to be played
    */
    void setWeeksToBePlayed(int n);

    /**
     * \brief Setter method for the Current Week
     * \param n setting value for current week
    */
    void setCurrentWeek(int n);

    /**
     * \brief Setter method for the Info code
     * \param n setting value for Info code
    */
    void setInfoCode(int n);

    /**
     * \brief Setter method for the factory delay
     * \param n setting value for factory delay
    */
    void setFactoryDelay(int n);

    /**
     * \brief Setter method for the number of players in the game
     * \param n setting value for number of players in the game
    */
    void setNumberOfPlayers(int n);

    /**
     * \brief setter method for parent widget
     * \param seeting value for parent_ui
    */
    void setParent_ui(QWidget *parent){parent_ui = parent;};





    /**
     * \brief Getter method for Game Id
     * \return Gid
    */
    int getGId();

    /**
     * \brief Getter method for instructor Id
     * \return Instrid
    */
    int getInstrId();

    /**
     * \brief Getter method for Factory Id
     * \return pFactid
    */
    int getPFactId();

    /**
     * \brief Getter method for distributor Id
     * \return pDistributorid
    */
    int getPDistributorId();

    /**
     * \brief Getter method for wholeseller Id
     * \return pWholesellerid
    */
    int getPWholesalerId();

    /**
     * \brief Getter method for retailer Id
     * \return pRetailerid
    */
    int getPRetailerId();

    /**
     * \brief getter method for the Consumer demand per week
     * \return consumerDemandPerWeek
    */
    std::vector<int> getConsumerDemandPerWeek()const{return consumerDemandPerWeek;}

    /**
     * \brief Getter method for Order Time dealy
     * \return orderDelay
    */
    int getOrderDelay();

    /**
     * \brief Getter method for Shipment delay
     * \return shipmentDelay
    */
    int getShipmentDelay();

    /**
     * \brief Getter method for Holding cost
     * \return holdingCost
    */
    double getHoldingCost();

    /**
     * \brief Getter method for Backorder Cost
     * \return backorderCost
    */
    double getBackorderCost();

    /**
     * \brief Getter method for Starting Inventory
     * \return startingInventory
    */
    int getStartingInventory();

    /**
     * \brief Getter method for weeks to be played
     * \return weeksToBePlayed
    */
    int getWeeksToBePlayed();

    /**
     * \brief Getter method for current week
     * \return currentWeek
    */
    int getCurrentWeek();

    /**
     * \brief Getter method for Info Code
     * \return InfoCode
    */
    int getInfoCode();

    /**
     * \brief Getter method for factory delay
     * \return factoryDelay
    */
    int getFactoryDelay();

    /**
     * \brief Getter method for number of players in the game
     * \return numberOfPlayers
    */
    int getNumberOfPlayers();

    /**
     * \brief Getter method for passwords generated
     * \return passwords
    */
    std::vector<std::string> getPassword()const{return passwords;}


    /**
     * \brief Getter method for players in game
     * \return parent_ui
    */
    std::vector<Player*> getPlayer()const{return Players;}

    /**
     * \brief Getter method for parent widget
     * \return parent_ui
    */
    QWidget * getParent_ui()const{return parent_ui;};


private:
    /**
    * \brief Attribute for Game Id
    */
    int gId;

    /**
    * \brief Attribute for Instructor Id
    */
    int InstrId;

    /**
    * \brief Attribute for Factory Id
    */
    int pFactId;

    /**
    * \brief Attribute for Distributor Id
    */
    int pDistributorId;

    /**
    * \brief Attribute for Wholeseller Id
    */
    int pWholesellerId;

    /**
    * \brief Attribute for Retailer Id
    */
    int pRetailerId;

    /**
    * \brief Attribute which maps playerId to orders to be executed vector
    */
    std::map<int, std::vector<Order*>> ordersToBeExecuted;

    /**
    * \brief Attribute which maps PlayerId to Shipment to be executed vector
    */
    std::map<int, std::vector<Shipment*>> shipmentsToBeExecuted;
    
    /**
    * \brief Attribute storing the players in the game
    */
    std::vector<Player*> Players;

    /**
    * \brief Attribute describing the consumer demand in a week
    */
    std::vector<int> consumerDemandPerWeek;

    /**
    * \brief Attribute for Order time delay
    */
    int orderDelay;

    /**
    * \brief Attribute for shipment time delay
    */
    int shipmentDelay;

    /**
    * \brief Attribute for Holding cost for a game
    */
    double holdingCost;

    /**
    * \brief Attribute for Back order cost for a game
    */
    double backorderCost;

    /**
    * \brief Attribute for Starting inventory
    */
    int StartingInventory;

    /**
    * \brief Attribute to define total no of weeks the game is being played
    */
    int weeksToBePlayed;

    /**
    * \brief Attribute for Current week
    */
    int currentWeek;

    /**
    * \brief Attribute for info code
    */
    int infoCode;

    /**
    * \brief Attribute for Factory time delay
    */
    int factoryDelay;

    /**
    * \brief Attribute for Number of Players in the game
    */
    int numberOfPlayers;

    /**
    * \brief Attribute for passwords for the players
    */
    std::vector<std::string> passwords;

    /**
    * \brief Attribute for linking with player UI
    */
    QWidget* parent_ui;
};

#endif // GAME_H
