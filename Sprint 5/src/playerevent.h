/**
 * \class PlayerEvent
 * \brief Set and get order and shipment properties between players in the game
 *
 */

#include "player.h"

#ifndef _PLAYER_EVENT_H
#define _PLAYER_EVENT_H

class PlayerInterface;

class PlayerEvent
{
protected:
    /**
    * \brief ID of the event
    */
    int eventId;
    /**
    * \brief number of beers in the transaction 
    */
    int numberOfBeers;
    /**
    * \brief week number when the order was executed
    */
    int orderedInWeek;
    /**
    * \brief receiver Player in the game
    */
    PlayerInterface *receiver = nullptr;

    /**
    * \brief week number when the shipment was executed
    */
    int shippedInWeek;
    /**
    * \brief ID of receiver player
    */
    int toPlayerId;
    /**
    * \brief ID of sender player
    */
    int fromPlayerId;
    /**
    * \brief ID of the game
    */
    int gId;

public:
    /**
    * \brief PlayerEvent constructor
    */
    PlayerEvent() {}
    /**
    * \brief PlayerEvent constructor with parameters
    * \param eventId
    * \param numberOfBeers
    * \param orderedInWeek 
    * \param receiver
    */
    PlayerEvent(int eventId, int numberOfBeers, int orderedInWeek, PlayerInterface *receiver) : eventId(eventId), numberOfBeers(numberOfBeers), orderedInWeek(orderedInWeek), receiver(receiver){};
    /**
    * \brief This method sets event ID
    * \param eId
    */
    int setEventId(int id)
    {
        this->eventId = id;
    }
    /**
    * \brief This method gets eventid
    * \return eventID
    */
    int getEventId() const
    {
        return eventId;
    }
    /**
     * \brief: This method sets weekOrder
     * \param week
    */
    void setOrderedInWeek(int week)
    {
        this->orderedInWeek = week;
    }
    /**
     * \brief: This method gets orderedInWeek
     * \return oderedInWeek
    */
    int getOrderedInWeek() const
    {
        return orderedInWeek;
    }
    /**
     * \brief: This method sets number of beers
     * \param numberOfBeers
    */
    void setNumberOfBeers(int numberOfBeers)
    {
        this->numberOfBeers = numberOfBeers;
    }
    /**
     * \brief: This method get number of beers
     * \return numberOfBeers
    */
    int getNumberOfBeers()
    {
        return numberOfBeers;
    }
    /**
     * \brief This method sets player ID
     * \param s
    */
    void setFromPlayerId(int s)
    {
        this->fromPlayerId = s;
    }
    /**
     * \brief This method return PlayerID
     * \return playerID
    */
    int getFromPlayerId()
    {
        return fromPlayerId;
    }
    /**
     * \brief This method sets toPlayer ID
     * \param playerID
    */
    void setToPlayerId(int playerID)
    {
        this->toPlayerId = playerID;
    }
    /**
     * \brief This method gets ToPlayer ID
     * \return toPlayerID
    */
    int getToPlayerId()
    {
        return toPlayerId;
    }
    /**
     * \brief: This method sets ShippedInweek
     * \param weekShipped
    */
    void setShippedInWeek(int weekShipped)
    {
        this->shippedInWeek = weekShipped;
    }
    /**
     * \brief: This method gets ShippedInweek
     * \return shippedInWeek
    */
    int getShippedInWeek()
    {
        return shippedInWeek;
    }
    /**
    * \brief this method set game ID
    * \param g
    */
    void setGId(int g)
    {
        this->gId = g;
    }
    /**
     * \brief This method gets game ID
     * \return gameID
    */
    int getGId()
    {
        return gId;
    }
    /**
     * \brief: This method sets receiver
     * \param pi
    */
    void setReceiver(PlayerInterface *pi)
    {
        this->receiver = pi;
    }
    /**
     * \brief: This method sets receiver
     * \return receiver
    */
    PlayerInterface *getReceiver()
    {
        return receiver;
    }
};

#endif
