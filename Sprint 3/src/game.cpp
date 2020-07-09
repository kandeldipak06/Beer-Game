#include "include/game.h"
#include "include/player.h"
#include "include/shipment.h"
#include "include/order.h"
#include "include/playerui.h"

Game::Game(){
    gId = InstrId = pFactId = pDistributorId = pWholesellerId = pRetailerId = 0;
    orderDelay = shipmentDelay = 2;
    holdingCost = 0.5;
    backorderCost = 1.0;
    StartingInventory = 12;
    weeksToBePlayed = 26;
    currentWeek = 0;
    infoCode = 0;
    factoryDelay = 1;
    numberOfPlayers = 0;
    consumerDemandPerWeek.assign(26, 4);
}

Game::~Game(){
    for(int i = 0; i < (int)Players.size(); i++){
        delete Players[i];
    }
    for(int i = 0; i < currentWeek; i++){
        for(auto k: ordersToBeExecuted[i])
            delete k;
    }
    for(int i = 0; i < currentWeek; i++){
        for(auto k: shipmentsToBeExecuted[i])
            delete k;
    }
    passwords.clear();
}

void Game::startGame(){
    Player *p1, *p2, *p3, *p4, *p5;
    p1 = new Player;
    p2 = new Player;
    p3 = new Player;
    p4 = new Player;
    p5 = new Player;

    Players.push_back(p1);
    Players.push_back(p2);
    Players.push_back(p3);
    Players.push_back(p4);
    Players.push_back(p5);

    p1->setPId(pFactId);
    p2->setPId(pDistributorId);
    p3->setPId(pWholesellerId);
    p4->setPId(pRetailerId);
    p5->setPId(gId * 10);

    p1->setGame(this);
    p2->setGame(this);
    p3->setGame(this);
    p4->setGame(this);
    p5->setGame(this);

    p1->setRole(1);
    p2->setRole(2);
    p3->setRole(3);
    p4->setRole(4);
    p5->setRole(5);

    PlayerUI * p1_ui = new PlayerUI(parent_ui, p1);
    p1_ui->show();

    PlayerUI * p2_ui = new PlayerUI(parent_ui, p2);
    p2_ui->show();

    PlayerUI * p3_ui = new PlayerUI(parent_ui, p3);
    p3_ui->show();

    PlayerUI * p4_ui = new PlayerUI(parent_ui, p4);
    p4_ui->show();

}    

void Game::executeOrdersForCurrentWeek(){
    for(int i = 0; i < numberOfPlayers; i++){
        ordersToBeExecuted[currentWeek][i]->executeOrder();
    }
}

void Game::executeShipmentsForCurrentWeek(){
    for(int i = 0; i < numberOfPlayers; i++){
        shipmentsToBeExecuted[currentWeek][i]->executeShipment();
    }
}


void Game::updatePlayerInventories(){
    //update inventories
    for(auto i: Players){
        if(i->getShipmentReceived() && i->getShipmentPlaced()){
            i->decreaseInventory(i->getOutgoingShipment());
            i->increaseInventory(i->getIncomingShipment());
            if(i->getOrderReceived()){
                if(i->getInventory() < i->getIncomingOrder()){
                    i->setBackorder(-i->getInventory() + i->getIncomingOrder());
                    i->setCost(i->getBackorder()*backorderCost);
                }else{
                    i->setCost((i->getInventory() - i->getIncomingOrder())*holdingCost);
                }
            }

        }
        i->setTotalCost(i->getTotalCost()+i->getCost());
        i->setCost(0);
    }
}

int Game::getConsumerOrderForWeek(int week){
    return consumerDemandPerWeek[week];
}

void Game::advanceWeek(){
    currentWeek++;
}

void Game::addOrder(const int& role, int numberOfBeers){
    Order *new_order = new Order;
    new_order->setEventId(currentWeek*10 + role);
    new_order->setGId(gId);
    new_order->setNumberOfBeers(numberOfBeers);
    new_order->setOrderedInWeek(currentWeek);
    new_order->setReceiver(getUpstream(role));
    new_order->setToPlayerId(getUpstream(role)->getPId());
    new_order->setFromPlayerId(Players[role-1]->getPId());

    ordersToBeExecuted[currentWeek].push_back(new_order);

}

void Game::addShipment(const int& role, int numberOfBeers){
    Shipment *new_shipment = new Shipment;
    new_shipment->setEventId(currentWeek*10 + role);
    new_shipment->setGId(gId);
    new_shipment->setNumberOfBeers(numberOfBeers);
    new_shipment->setOrderedInWeek(currentWeek);
    new_shipment->setReceiver(getDownstream(role));
    new_shipment->setToPlayerId(getDownstream(role)->getPId());
    new_shipment->setFromPlayerId(Players[role-1]->getPId());

    shipmentsToBeExecuted[currentWeek].push_back(new_shipment);
}


void Game::addPlayer(Player* new_player){
    Players.push_back(new_player);
}

Player* Game::getDownstream(const int& role){
    return Players[role];
}

Player* Game::getUpstream(const int& role){
    if(role == 1)
        return  Players[role-1];
    return Players[role-2];
}

std::vector<std::string> Game::generatePasswords(){
    const char *seq = "abcdefghijklmnopqrstuvwxyz123456789ABCDEFGHIJKLMNOP";
    std::string pass;
    //int length;
    for(int j = 0; j < numberOfPlayers; j++){
        for (int i = 0; i < 10; ++i)
            pass[i]= seq[rand()%50];
        passwords.push_back(pass);
    }
    return passwords;
}

//setters

void Game::setGId(int n_id){
    gId = n_id;
    return;
}

void Game::setInstrId(int n_id){
    InstrId = n_id;
    return;
}

void Game::setPFactId(int n_id){
    pFactId = n_id;
    return;
}

void Game::setPDistributorId(int n_id){
    pDistributorId = n_id;
    return;
}

void Game::setPWholesalerId(int n_id){
    pWholesellerId = n_id;
    return;
}

void Game::setPRetailerId(int n_id){
    pRetailerId = n_id;
    return;
}

void Game::setOrderDelay(int n){
    orderDelay = n;
    return;
}

void Game::setShipmentDelay(int n){
    shipmentDelay = n;
    return;
}

void Game::setHoldingCost(double n){
    holdingCost = n;
    return;
}

void Game::setBackorderCost(double n){
    backorderCost = n;
    return;
}

void Game::setStartingInventory(int n){
    StartingInventory = n;
    return;
}

void Game::setWeeksToBePlayed(int w){
    weeksToBePlayed = w;
    return;
}

void Game::setCurrentWeek(int w){
    currentWeek = w;
    return;
}

void Game::setInfoCode(int n){
    infoCode = n;
    return;
}

void Game::setFactoryDelay(int n){
    factoryDelay = n;
    return;
}

void Game::setNumberOfPlayers(int n){
    numberOfPlayers = n;
    return;
}



//getters

int Game::getGId(){
    return gId;
}

int Game::getInstrId(){
    return InstrId;
}

int Game::getPFactId(){
    return pFactId;
}

int Game::getPDistributorId(){
    return pDistributorId;
}

int Game::getPWholesalerId(){
    return pWholesellerId;
}

int Game::getPRetailerId(){
    return pRetailerId;
}

int Game::getOrderDelay(){
    return orderDelay;
}

int Game::getShipmentDelay(){
    return shipmentDelay;
}

double Game::getHoldingCost(){
    return holdingCost;
}

double Game::getBackorderCost(){
    return backorderCost;
}

int Game::getStartingInventory(){
    return StartingInventory;
}

int Game::getWeeksToBePlayed(){
    return weeksToBePlayed;
}

int Game::getCurrentWeek(){
    return currentWeek;
}

int Game::getInfoCode(){
    return infoCode;
}


int Game::getFactoryDelay(){
    return factoryDelay;
}

int Game::getNumberOfPlayers(){
    return numberOfPlayers;
}




