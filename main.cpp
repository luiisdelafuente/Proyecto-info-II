#include <QApplication>
#include <QFont>
#include <QPushButton>
#include "inicio.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    inicio * pi;
    pi=new inicio();
    pi->show();

    return app.exec();
}
