

#include "camino.h"


camino:: camino(FILE*FP, QWidget * parent): QWidget(parent)
{


	setGeometry(400,200,550,150);
	setFixedSize(550,350);
	setWindowTitle("Field Service");



	accion=new QLabel("Degradacion de imagen y pixelacion ",this);
	accion->setGeometry(150,100,350,80);
	accion->setFont(QFont("Arial",14));


	pregunta=new QLabel(this);
	pregunta->setGeometry(185,200,200,20);
	pregunta->setText("¿surge en todas las bocas?");
	pregunta->setFont(QFont("Arial",11));




	si=new QPushButton("Si",this);
	si->setGeometry(450, 300, 80, 30);

	no=new QPushButton("no",this);
	no->setGeometry(50, 300, 80, 30);


	connect(no,SIGNAL(clicked()),this,SLOT(refrescarventana()));

}

void camino::refrescarventana()
{
	accion->setText("Comprobar el estado de los divisores \n          y o recablear bocas");
	accion->setFont(QFont("Arial",14));

	pregunta->setGeometry(260,200,200,20);
	pregunta->setText("¿Persiste?");

	connect(no,SIGNAL(clicked()),this,SLOT(cerrar()));
}

// Para probar que se puede reutilizar el boton si/no para conectar diferentes cosas
void camino::cerrar()
{

	close();
}
