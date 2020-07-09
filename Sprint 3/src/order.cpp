#include "include/order.h"
#include "include/player.h"

Order::Order(){

}

Order::~Order(){

}


void Order::executeOrder(){
    if(!receiver->getOrderReceived()){
        receiver->receiveOrder(numberOfBeers);
        receiver->setShipmentReceived(true);
    }
}
