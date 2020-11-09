#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QFont>
#include <iostream>
#include <string>

#include "ventana2.h"
#include "ventana3.h"
#include "principal.h"
using namespace std;

Ventana3::Ventana3(FILE*FP,QWidget *parent) : QWidget(parent)
{
	setGeometry(400,200,550,150);
	setFixedSize(550,350);
	setWindowTitle("Paso 2");

	accion=new QLabel(this);
	accion->setGeometry(100,20,400,200);
	accion->setText("Comprobar el estado de los divisores \n             y recablear bocas");
	accion->setFont(QFont("Arial",15));

	pregunta=new QLabel(this);
	pregunta->setGeometry(235,100,500,200);
	pregunta->setText("¿Persiste?");
	pregunta->setFont(QFont("Arial",12));

	si3=new QPushButton("Si",this);
	si3->setGeometry(450, 300, 80, 30);

	no3=new QPushButton("No",this);
	no3->setGeometry(50, 300, 80, 30);

	connect(si3,SIGNAL(clicked()),this,SLOT(mostrarVentana4()));
	connect(no3,SIGNAL(clicked()),this,SLOT(nopersiste()));
	pventana4=NULL;
	FPP=FP;
}

void Ventana3::mostrarVentana4()
{
	struct visita_tecnica_s vt;
    char anadir [80]=("\ Se comprobo el estado de los divisores y se recableo la instalacion");

	fseek(FPP,0,SEEK_CUR);
	fread(&vt,sizeof(vt),1,FPP);
	fseek(FPP,sizeof(vt)*-1,SEEK_CUR);




	strcat(vt.trabajo_realizado,anadir); // Concatena strings con el trabajo que se hizo
	//cout<<"Lo guardado es : "<<vt.trabajo_realizado;
	printf("\n\n\n FPP=%p\n\n\n",FPP);
	fwrite(&vt,sizeof(vt),1,FPP);
	fseek(FPP,sizeof(vt)*-1,SEEK_CUR);

		if(!pventana4)
	{
		pventana4=new Ventana4(FPP);	//Le envio a la ventana 3 el puntero al archivo;
	}
		hide();
		pventana4->show();
}

void Ventana3::nopersiste()//Finaliza el programa
{

	struct visita_tecnica_s vt;
    char anadir [80]=("//Se comprobo el estado de los divisores y se recableo la instalacion");

	fseek(FPP,0,SEEK_CUR);
	fread(&vt,sizeof(vt),1,FPP);
	strcat(vt.trabajo_realizado,anadir);
	fseek(FPP,sizeof(vt)*-1,SEEK_CUR);
	fwrite(&vt,sizeof(vt),1,FPP);

	close();

}
