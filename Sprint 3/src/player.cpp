#include "include/player.h"
#include "include/game.h"

Player::Player(){
    pId = role = 0;
    inventory = 12;
    backorder = incomingOrder = incomingShipment = outgoingShipment = 0;
    cost = totalCost = 0.0;
    orderReceived = shipmentReceived = orderPlaced = shipmentPlaced = false;
    demand = 0;
    game = nullptr;
}


Player::~Player(){

}

void Player::placeOrder(int numberOfBeers){
    game->addOrder(role, numberOfBeers);
    orderPlaced = true;
}

void Player::placeShipment(int numberOfBeers){

    game->addShipment(role, getAvailableShipment(numberOfBeers));
    shipmentPlaced = true;
}

int Player::getAvailableShipment(int n_demand){
    if(inventory > n_demand){
        decreaseInventory(n_demand);
        return n_demand;
    }
    decreaseInventory(inventory);
    return inventory;
}

void Player::receiveShipment(int receivedBeers){
    if(!shipmentReceived){
        incomingShipment = receivedBeers;
        shipmentReceived = true;
    }
}

void Player::receiveOrder(int orderedBeers){
    if(!orderReceived){
        incomingOrder = orderedBeers;
        orderReceived = true;
    }
}

void Player::decreaseInventory(int numberOfBeers){
    inventory = inventory - numberOfBeers;
}

void Player::increaseInventory(int numberOfBeers){
    inventory = numberOfBeers + inventory;
}

