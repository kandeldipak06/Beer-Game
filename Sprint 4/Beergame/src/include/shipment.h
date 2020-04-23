#ifndef SHIPMENT_H
#define SHIPMENT_H


#include "playerEvent.h"



class Shipment : public PlayerEvent
{
public:
    /**
     * \brief Constructor for Shipment class, sets the default values for game class
    */
    Shipment();

    /**
     * \brief distructor for Shipment class
    */
    ~Shipment();

    /**
     * \brief method for executing shipment
    */
    void executeShipment();

};

#endif // SHIPMENT_H
