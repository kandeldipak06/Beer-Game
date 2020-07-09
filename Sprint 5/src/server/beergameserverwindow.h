/** 
 * \class BeerGameServerWindow
 * \brief This is the UI for the server side implementation for the game.
 */

#ifndef BEERGAMESERVERWINDOW_H
#define BEERGAMESERVERWINDOW_H

#include <QMainWindow>

#include "beergameserver.h"

namespace Ui
{
class BeerGameServerWindow;
}

class BeerGameServerWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * \brief Constructor for BeerGameServerWindow class 
     * \param parent
     */
    explicit BeerGameServerWindow(QWidget *parent = nullptr);
    /**
     * \brief Destructor for BeerGameServer class 
     *
     */
    ~BeerGameServerWindow();

private slots:
    /**
     * \brief button to start the server
     */ 
    void on_start_server_btn_clicked();
    /**
     * \brief button to stop the server
     */ 
    void on_stopServerBtn_clicked();

private:
    /**
     * \brief UI object for BeerGameServerWindow
     */
    Ui::BeerGameServerWindow *ui;
    /**
     * \brief BeerGameServer Object
     */
    BeerGameServer *beerGameServer;
};

#endif // BEERGAMESERVERWINDOW_H
