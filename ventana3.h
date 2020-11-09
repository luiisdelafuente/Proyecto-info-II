#pragma once
#include <QApplication>
#include  <QWidget>
#include  <QLabel>
#include  <QTextEdit>
#include  <QPushButton>

#include "principal.h"
#include "ventana2.h"
#include "ventana4.h"
class inicio;
class Ventana2;
class Ventana4;

class Ventana3:public QWidget
{
	Q_OBJECT

	private:
	QLabel * accion;
	QLabel * pregunta;
	QPushButton * si3;
	QPushButton * no3;

	Ventana4 * pventana4;



	public:
		Ventana3(FILE*FP,QWidget*parent=0);
		FILE *FPP;

	public slots:
	void mostrarVentana4();
	void nopersiste();
};
