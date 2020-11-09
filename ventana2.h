
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

class Ventana2: public QWidget
{
	Q_OBJECT
private:
	QLabel * titulo2;
	QLabel * pregunta2;
	QPushButton * si2;
	QPushButton * no2;

	Ventana3* pventana3;

public:
	Ventana2(FILE*,QWidget * parent=0);
	FILE *FPP;

public slots:
	void mostrarVentana3();

};
