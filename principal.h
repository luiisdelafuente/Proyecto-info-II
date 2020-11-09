#pragma once

#include  <QWidget>
#include  <QLabel>
#include  <QTextEdit>
#include  <QPushButton>
#include <QLineEdit>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#include "ventana2.h"



class Ventana2;
class Ventana4;


class inicio: public QWidget
{
	Q_OBJECT

private:
	QTextEdit * tecnico;
	QTextEdit* empresa;
	QTextEdit * domicilio;
	QTextEdit * fecha;
	QPushButton *siguiente;
	QPushButton *resumen;

	QLabel *informacion1;
	QLabel *informacion2;
	QLabel *informacion3;
	QLabel *informacion4;
	QLabel *titulo;


	Ventana2 * pventana2;


public:
	inicio(QWidget * parent=0);
	QString getTecnico();
	QString getEmpresa();
	QString getDomicilio();
	QString getFecha();

	FILE *FP;

public slots:
	void mostrarVentana2();
	void verresumen();


};

struct visita_tecnica_s
{
	char tecnico [40];
	char empresa [40];
	char fecha [40];
	char domicilio[40];
	char trabajo_realizado[200];
};
