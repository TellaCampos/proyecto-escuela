#include "calificacion.h"
#include "ui_calificacion.h"

calificacion::calificacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calificacion)
{
    ui->setupUi(this);
}

calificacion::~calificacion()
{
    delete ui;
}

void calificacion::on_pushButton_clicked()
{
    hide();
    alumnos *atras = new alumnos(this);
    atras ->show();

}
