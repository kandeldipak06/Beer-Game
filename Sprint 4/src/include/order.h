#ifndef ORDER_H
#define ORDER_H

#include "playerEvent.h"



class Order : public PlayerEvent
{
public:
    /**
     * \brief Constructor for Shipment class, sets the default values for game class
    */
    Order();

    /**
     * \brief distructor for Shipment class
    */
    ~Order();

    /**
     * \brief method for executing shipment
    */
    void executeOrder();

};

#endif // ORDER_H
