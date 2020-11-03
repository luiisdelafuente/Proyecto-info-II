#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QFont>

#include "principal.h"
#include "ventana2.h"

inicio:: inicio (QWidget * parent): QWidget(parent)
{
	setGeometry(400,200,550,150);
	setFixedSize(550,350);
	setWindowTitle("Field Service");

	titulo=new QLabel("Bienvenido",this);
	titulo->setFont(QFont("Arial",18,QFont::Bold));
	titulo->setGeometry(5,5,150,60);


	informacion1=new QLabel(this);
	informacion1->setGeometry(145,100,60,20);
	informacion1->setText("Tecnico");
	informacion1->setFont(QFont("Arial",11));

	tecnico= new QTextEdit(this);
	tecnico->setGeometry(225,100,150,25);





	informacion2=new QLabel(this);
	informacion2->setGeometry(140,150,80,20);
	informacion2->setText("Contratista");
	informacion2->setFont(QFont("Arial",11));

	empresa= new QTextEdit(this);
	empresa->setGeometry(225,150,150,25);


	informacion3=new QLabel(this);
	informacion3->setGeometry(145,200,80,30);
	informacion3->setText("Domicilio");
	informacion3->setFont(QFont("Arial",11));

    domicilio= new QTextEdit(this);
	domicilio->setGeometry(225,200,150,25);

	pventana2=NULL;

	siguiente=new QPushButton("Siguiente",this);
	siguiente->setGeometry(450, 300, 80, 30);
	connect(siguiente,SIGNAL(clicked()),this,SLOT(mostrarVentana2()));
}

void inicio::mostrarVentana2()
{
	if(!pventana2)
	{
		pventana2=new Ventana2();
	}
		hide();
		pventana2->show();
}
