#include "alumnos.h"
#include "ui_alumnos.h"

alumnos::alumnos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alumnos)
{
    ui->setupUi(this);
}

alumnos::~alumnos()
{
    delete ui;
}

void alumnos::on_alumnos_accepted()
{

}

void alumnos::on_pushButton_clicked()
{
    hide();
    calificacion *cali = new calificacion(this);
    cali ->show();

}

void alumnos::on_pushButton_2_clicked()
{
    hide();
    horario *hora = new horario(this);
    hora ->show();

}

void alumnos::on_pushButton_3_clicked()
{
    hide();
    menu *main = new menu(this);
    main ->show();

}
