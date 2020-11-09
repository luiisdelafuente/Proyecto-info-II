#pragma once
#include <QApplication>
#include  <QWidget>
#include  <QLabel>
#include  <QTextEdit>
#include  <QPushButton>

#include "principal.h"
#include "ventana3.h"

class inicio;
class Ventana3;


class Ventana4:public QWidget
{
	Q_OBJECT

	private:
	QLabel * accion;
	QLabel * pregunta;
	QPushButton * si4;
	QPushButton * no4;





	public:
		Ventana4(FILE*FP,QWidget*parent=0);
		FILE*FPP;


	public slots:

		void finalizar();
};
