
#pragma once

#include "inicio.h"

class camino: public QWidget
{
	Q_OBJECT

private:
	QLabel *accion;
	QLabel *pregunta;
	QLabel *otracosa;
	QPushButton * si;
	QPushButton * no;

public:
	camino(FILE*FP,QWidget * parent=0);

public slots:
	void refrescarventana();
	void cerrar();

};


