#include "escuelaa.h"
#include "alta.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    escuelaa w;
    w.show();


    return a.exec();
}
