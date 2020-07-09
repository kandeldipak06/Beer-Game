#include "include/shipment.h"
#include "include/player.h"
Shipment::Shipment(){

}

Shipment::~Shipment(){

}


void Shipment::executeShipment(){
    if(!receiver->getShipmentReceived()){
        receiver->receiveShipment(numberOfBeers);
        receiver->setShipmentReceived(true);
    }

}
