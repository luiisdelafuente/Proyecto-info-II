#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QFont>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;
#include "inicio.h"
#include "camino.h"

inicio:: inicio (QWidget * parent): QWidget(parent)
{

	FP=NULL;
	pcamino=NULL;
	setGeometry(400,200,550,150);
	setFixedSize(550,350);
	setWindowTitle("Field Service");

	titulo=new QLabel("Bienvenido",this);
	titulo->setFont(QFont("Arial",18,QFont::Bold));
	titulo->setGeometry(5,5,150,60);


	informacion1=new QLabel(this);
	informacion1->setGeometry(145,100,60,20);
	informacion1->setText("Tecnico: ");
	informacion1->setFont(QFont("Arial",11));

	tecnico= new QTextEdit(this);
	tecnico->setGeometry(225,100,150,20);


	informacion2=new QLabel(this);
	informacion2->setGeometry(140,150,80,20);
	informacion2->setText("Contratista");
	informacion2->setFont(QFont("Arial",11));

	empresa= new QTextEdit(this);
	empresa->setGeometry(225,150,150,20);


	informacion3=new QLabel(this);
	informacion3->setGeometry(145,200,80,30);
	informacion3->setText("Domicilio: ");
	informacion3->setFont(QFont("Arial",11));

    domicilio= new QTextEdit(this);
	domicilio->setGeometry(225,200,150,20);

	informacion4=new QLabel(this);
	informacion4->setGeometry(148,250,80,30);
	informacion4->setText("Fecha:");
	informacion4->setFont(QFont("Arial",11));
	fecha= new QTextEdit(this);
	fecha->setGeometry(225,250,150,20);




	siguiente=new QPushButton("Siguiente",this);
	siguiente->setGeometry(450, 300, 80, 30);

	connect(siguiente,SIGNAL(clicked()),this,SLOT(cargararchivo()));

}

void inicio::cargararchivo()
{
	struct visita_tecnica_s vt;
	FILE *FP;

	if((FP=fopen("BasedeDatos","a+b"))==NULL)
	{
		printf("Error al abrir el archivo");
	}


	const char *aux=getTecnico().toStdString().c_str();
	strcpy(vt.tecnico,aux);
	aux=getDomicilio().toStdString().c_str();
	strcpy(vt.domicilio,aux);
	aux=getFecha().toStdString().c_str();
	strcpy(vt.fecha,aux);
	aux=getEmpresa().toStdString().c_str();
	fwrite(&vt,sizeof(vt),1,FP);
	fseek(FP,sizeof(vt)*-1,SEEK_CUR);
	fseek(FP,0,SEEK_CUR);

	if(!pcamino)
	{
		pcamino=new camino(FP);
	}
	hide();
	pcamino->show();
}


	QString inicio::getTecnico()
	{

		return tecnico->toPlainText();

	}
	QString inicio::getDomicilio()
	{
		return domicilio->toPlainText();
	}
	QString inicio::getFecha()
	{
		return fecha->toPlainText();
	}
	QString inicio::getEmpresa()
	{
		return empresa->toPlainText();
	}

