#include "horario.h"
#include "ui_horario.h"
#include  <QMessageBox>

horario::horario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::horario)
{
    ui->setupUi(this);
}

horario::~horario()
{
    delete ui;
}

void horario::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"Warning","Desea eliminar la clase");
}

void horario::on_pushButton_clicked()
{
    hide();
    menu *main = new menu(this);
    main ->show();

}
