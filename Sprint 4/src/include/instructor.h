#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <iostream>
#include <vector>
#include <string>

class Game;
class Instructor
{
public:

    /**
    * \brief Default constructor for instructor, creates a default Instuctor object
    */
    Instructor();
    /**
    * \brief distructor for instructor
    */
    ~Instructor();

    /**
     * \brief Displays status of game at that point of time
    */
    void showGamesStatus();

    /**
     * \brief creates a new game for the instructor object
    */
    int createGame();

    /**
     * \brief creates a new series of games for the instructor object
     * \param numOfGames is the number of games to be created
    */
    std::vector<int> createGames(int numOfGames);

    /**
     * \brief Setter method for the instructor Id
     * \param n_instrId seeting value of instructor Id
    */
    void setInstrId(int n_instrId){instrId = n_instrId;}


    /**
     * \brief Setter method for the instructor Email
     * \param n_instrEmail seeting value of instructor Email
    */
    void setInstrEmail(std::string const n_instrEmail){instrEmail = n_instrEmail;}


    /**
     * \brief Setter method for the instructor Password
     * \param n_instrId seeting value of instructor Password
    */
    void setInstrPassword(std::string const n_instrPassword){instrPassword = n_instrPassword;}

    /**
     * \brief Setter method for the games
     * \param game_instance seeting value of games
    */
     void setGames(const std::vector<Game*> game_instance){games = game_instance;}

    /**
     * \brief Getter method for instructor Id
     * \return instrId
    */
    int getInstrId()const{return instrId;}

    /**
     * \brief Getter method for instructor Email
     * \return instrEmail
    */
    std::string getInstrEmail()const{return instrEmail;}

    /**
     * \brief Getter method for instructor Password
     * \return instrPassword
    */
    std::string getInstrPassword()const{return instrPassword;}

    /**
     * \brief Getter method for games created by instructor
     * \return games
    */
    std::vector<Game*> getGames()const{return games;}


private:
    /**
    * \brief Attribute for Instructor Id
    */
    int instrId;

    /**
    * \brief Attribute for Instructor Email
    */
    std::string instrEmail;

    /**
    * \brief Attribute for Instructor Password
    */
    std::string instrPassword;

    /**
    * \brief Attribute for games managed by instructor
    */
    std::vector<Game*> games;

};

#endif // INSTRUCTOR_H
