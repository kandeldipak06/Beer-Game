#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <string>
#include <vector>

#include "game.h"
#include "instructorwindow.h"
#include "ui_instructorwindow.h"

/**
 * \class Instructor
 * \brief This class provides a interface of Instructor.  Instructor class has methods to
 *          set and get Id, Email, Password and Games
 *          Moreover, it has methods to show game status, create a game and create games..
 */ 
class InstructorDialog;

class Instructor
{
private:
    /**
     * \brief: ID of the instructor
    */
    int instrId;
    /**
     * \brief: email of the instructor
    */
    std::string instrEmail;
    /**
     * \brief: password of the instructor
    */
    std::string instrPassword;
    /**
     * \brief games vector 
    */
    std::vector<Game> games;
    /**
     * \brief UI for instructor
    */
    Ui::InstructorWindow *ui;
    /**
     * \brief parent widget
    */
    QWidget *uiParent;

public:
    /**
     * \brief shows game status
    */
    void showGamesStatus();

    /**
     * \brief creates all games specified
     * \return 1 game
    */
    Game createGame();
    /**
     * \brief creates all games specified
     * \param numberOfGames number of Games
     * \return vector of games
    */
    std::vector<Game> createGames(int numberOfGames);

    /**
     * \brief creates all games specified
     * \param backorder, holdingCost, orderDelay, totalWeeks, startInventory, factDelay
     * \return vector of games
    */
    std::vector<Game> createGames(double backorder, double holdingCost, int orderDelay, int totalWeeks, int startInventory, int factDelay);

    /**
     * \brief setting up the UI for instructor
     * \param ui
     * 
    */
    void setUi(Ui::InstructorWindow *ui);

    /**
     * \brief setting main window
     * \param parent
    */
    void setWindowParent(QWidget *parent);

    /**
     * \brief This method sets the email of instructor
     * \param email Instructor's one.
    */
    void setInstrEmail(std::string email);
    /**
     * \brief This method sets the password of instructor
     * \param password Instructor's one.
    */
    void setInstrPassword(std::string password);
    /**
     * \brief This method sets the id of instructor
     * \param id Instructor's one.
    */
    void setInstrId(int id);

    /**
     * \brief This method sets the vector of games
     * \param gms Game vector to be added to vector of games
    */
    void setGames(std::vector<Game> gms); //
    /**
     * \brief This method gets the vector of games
     * \return vector of Games
    */
    std::vector<Game> getGames();
    /**
     * \brief This method gets the email of instructor
     * \return email of instructor
    */
    std::string getInstrEmail();
    /**
     * \brief This method gets the password of instructor
     * \return password of instructor
    */
    std::string getInstrPassword();
    /**
     * \brief This method gets the ID of instructor
     * \return Id of Instructor.
    */
    int getInstrId();
};

#endif //INSTRUCTOR_H
