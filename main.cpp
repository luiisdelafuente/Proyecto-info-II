#include <QApplication>


#include "principal.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

	inicio *p1 = new inicio();
	p1->show();


    return app.exec();
}
