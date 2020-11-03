#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QFont>

#include "ventana2.h"

Ventana2::Ventana2(QWidget *parent) : QWidget(parent)
{
	setGeometry(400,200,550,150);
	setFixedSize(550,350);
	setWindowTitle("Paso 1");

	titulo2=new QLabel(this);
	titulo2->setGeometry(160,30,300,40);
	titulo2->setText("Pixelacion en la Imagen");
	titulo2->setFont(QFont("Arial",15,QFont::Bold));

	pregunta2=new QLabel(this);
	pregunta2->setGeometry(150,150,300,40);
	pregunta2->setText("¿Se presenta en todas las bocas?");
	pregunta2->setFont(QFont("Arial",12));

	si2=new QPushButton("Si",this);
	si2->setGeometry(450, 300, 80, 30);

	no2=new QPushButton("No",this);
	no2->setGeometry(50, 300, 80, 30);

}

