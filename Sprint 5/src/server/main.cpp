#include "beergameserverwindow.h"

#include <QApplication>
#include "beergameserverwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BeerGameServerWindow w;
    w.show();

    return a.exec();
}
