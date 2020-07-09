#include "clientinterface.h"
#include <QApplication>


/*! \mainpage Beer Game Sprint 5 Team 29
 *
 * \section runsteps How to run?
 *
 * \subsection program Run the program
 * 
 * \subsection Run the server
 * 
 * cd build (or any directory where the program is built) \n
 * ./beergame 
 * 
 * \subsection Run the client
 * cd build
 * ./beergame-players
 * 
 * \subsection testcases Run testcases
 * ./beergame-tests \n
 */ 


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientInterface w;
    w.show();
    return a.exec();
}
