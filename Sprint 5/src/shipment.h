/**
 * \class Shipment
 * \brief Child class of PlayerEvent class
 *
 */

#include "playerevent.h"
#include "player.h"

class Player;

#ifndef _SHIPMENT_H
#define _SHIPMENT_H

class Shipment : public PlayerEvent
{
public:
    /**
     * \brief: This method represents the Shipment constructor
     */
    Shipment();
    /**
     * \brief: This method represents the Shipment constructor with parameter values
     * \param eventId
     * \param nBeers
     * \param execInWeek
     * \param receiver
     */
    Shipment(int eventId, int nBeers, int execInWeek, PlayerInterface* receiver);
    /**
     * @brief: This method calls the receiveShipment on the receiver
     */
    void executeShipment();
};

#endif
