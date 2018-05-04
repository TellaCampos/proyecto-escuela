#include "agenda.h"
#include "ui_agenda.h"
#include  <QMessageBox>

agenda::agenda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agenda)
{
    ui->setupUi(this);
}

agenda::~agenda()
{
    delete ui;
}

void agenda::on_pushButton_4_clicked()
{
    hide();
    menu *main = new menu(this);
    main ->show();

}

void agenda::on_pushButton_clicked()
{
    hide();
    agePadres *padres = new agePadres(this);
    padres ->show();

}

void agenda::on_pushButton_2_clicked()
{
    hide();
    agenmaestros *masters = new agenmaestros(this);
    masters ->show();

}

void agenda::on_pushButton_3_clicked()
{
    hide();
    evento *even = new evento(this);
    even ->show();

}

void agenda::on_pushButton_5_clicked()
{
    QMessageBox::information(this,"Warning","¿Desea eliminar el evento?");
}
