/**
 * \author Dipak Kandel
 * \author Felix Koranteng
 * \date 2020-4-2
 *
 * \bug For this version do not use generate password button in Instructor UI Page
 *
 *
 * \copyright GNU public Licence
 *
 * \mainpage The Beer Game
 *
 * \section Introduction
 * The following project is in it's developing process for the complete Beer
 * game.The beer game is an online game intended for students to better understand ho
 * wsupply chain works in a real world situation, applying the theory learned in class an
 * d practicing decision making. Therefore it is a functional type of game. This project
 * simulates the way beer is being ordered and delivered from production and factory,going
 * to distributor, then wholesaler and then to retailer and consumer.
 *
 * \section Guide Execution procedure
 *  \subsection Beergame Compiling Procedure:
 *   mkdir build && cd build && cmake ..
 *
 *   \subsubsection RunUI Testing UI
 *   ./beergame
 *
 *  \subsubsection Testing Testing test cases
 *   ./beergame-tests
 *
 *  \subsubsection Making Generate Documentation
 *   make doc
 *
 *   \subsubsection Running View documentation
 *   chromium-browser ../doc/html/index.html
 *
 *
 *
*/








#include "include/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])

{
    unsigned int time_ui = static_cast<unsigned int>( time(NULL) );
    srand(time_ui);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
