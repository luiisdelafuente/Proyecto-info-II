#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QFont>


#include "ventana3.h"
#include "ventana4.h"

#include "principal.h"

Ventana4::Ventana4(FILE*FP,QWidget *parent) : QWidget(parent)
{
	setGeometry(400,200,550,150);
	setFixedSize(550,350);
	setWindowTitle("Paso 3");

	accion=new QLabel(this);
	accion->setGeometry(100,20,400,200);
	accion->setText("Cambiar Fuente , si persiste cambiar decodificador");
	accion->setFont(QFont("Arial",12));

	pregunta=new QLabel(this);
	pregunta->setGeometry(235,100,500,200);
	pregunta->setText("¿Persiste?");
	pregunta->setFont(QFont("Arial",12));

		no4=new QPushButton("No, Finalizar",this);
	no4->setGeometry(440, 300, 100, 30);

	si4=new QPushButton("No, Llamar  despacho y finalizar",this);
	si4->setGeometry(40, 300, 180, 30);

	FPP=FP;
	connect(no4,SIGNAL(clicked()),this,SLOT(finalizar()));

}

void Ventana4::finalizar()
{
	struct visita_tecnica_s vt;
	char anadir [80]=("\ \n Se reemplazo(fuente de alimentacion y/o decodificador");

	fseek(FPP,0,SEEK_CUR);
	fread(&vt,sizeof(vt),1,FPP);
	fseek(FPP,sizeof(vt)*(-1),SEEK_CUR);
	strcat(vt.trabajo_realizado,anadir); // Concatena strings con el trabajo que se hizo

	printf("\n\n\n FPP=%p\n\n\n",FPP);
	fwrite(&vt,sizeof(vt),1,FPP);
	//fseek(FPP,sizeof(vt)*-1,SEEK_CUR);

	close();
}
