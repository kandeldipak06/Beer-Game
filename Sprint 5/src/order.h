#ifndef ORDER_H
#define ORDER_H

#include "playerevent.h"
#include "player.h"

class Player;

/**
 * \class Order
 * \brief Child class of PlayerEvent class
 *
 */

class Order : public PlayerEvent
{
public:
    /**
     * \brief: This method represents the Order constructor
    */
    Order();
    /**
     * \brief: This method represents the Order constructor with parameters
     * \param eventId
     * \param nBeers
     * \param execInWeek
     * \param receiver
    */
    Order(int eventId, int nBeers, int execInWeek, PlayerInterface* receiver);
    /**
     * \brief: This method calls the receiveOrder on the receiver
    */
    void executeOrder();
};

#endif //ORDER_H
