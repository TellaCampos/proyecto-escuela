#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
    hide();
    alumnos *ventanaalumno = new alumnos(this);
    ventanaalumno ->show();

}

void menu::on_pushButton_2_clicked()
{
    hide();
    agenda *agendageneral = new agenda(this);
    agendageneral ->show();

}

void menu::on_pushButton_3_clicked()
{
    hide();
    MateriasMaestro *materias = new MateriasMaestro(this);
    materias ->show();


}
