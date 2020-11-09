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
#include "principal.h"
#include "ventana2.h"
#include "ventana4.h"

inicio:: inicio (QWidget * parent): QWidget(parent)
{

	FP=NULL;
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


	pventana2=NULL;

	siguiente=new QPushButton("Siguiente",this);
	siguiente->setGeometry(450, 300, 80, 30);
	connect(siguiente,SIGNAL(clicked()),this,SLOT(mostrarVentana2()));

	resumen=new QPushButton("Resumen",this);
	resumen->setGeometry(50, 300, 80, 30);
	connect(resumen,SIGNAL(clicked()),this,SLOT(verresumen()));

}

void inicio::mostrarVentana2()
{
	struct visita_tecnica_s vt;
	FILE *FP;

	const char *aux=getTecnico().toStdString().c_str();
	strcpy(vt.tecnico,aux);
	aux=getDomicilio().toStdString().c_str();
	strcpy(vt.domicilio,aux);
	aux=getFecha().toStdString().c_str();
	strcpy(vt.fecha,aux);
	aux=getEmpresa().toStdString().c_str();
	strcpy(vt.empresa,aux);

	strcpy(vt.trabajo_realizado," ");




	if((FP=fopen("BASE_DATOS","a+b"))==NULL)
	{
		printf("Error al abrir arrchivo ");
	}

	fwrite(&vt,sizeof(vt),1,FP);
	fseek(FP,sizeof(vt)*-1,SEEK_CUR);





	if(!pventana2)//Ventana 2
	{
		pventana2=new Ventana2(FP);	//Le envio a la ventana 2 el puntero al archivo;
	}
		hide();
		pventana2->show();
}

void inicio::verresumen()
{
	if((FP=fopen("BASE_DATOS","a+b"))==NULL)
	{
		printf("Error al abrir arrchivo ");
	}


	struct visita_tecnica_s vt;
	fseek(FP,sizeof(vt)*1,SEEK_SET);

	fread(&vt,sizeof(vt),1,FP);
	while(!feof(FP))
	{

		printf("\n\n Tecnico: %s  \nEmpresa: %s   \nFecha: %s \nDomicilio: %s \nTrabajo realizado: %s",vt.tecnico,vt.empresa,vt.fecha,vt.domicilio,vt.trabajo_realizado);
		fread(&vt,sizeof(vt),1,FP);
	}
	fseek(FP,sizeof(vt),SEEK_END);
}



//getters
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
