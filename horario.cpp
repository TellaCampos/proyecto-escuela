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

void horario::on_pushButton_3_clicked()
{
    ui->tablaHorario->clear();
    ui->tablaHorario->setRowCount(10);
    ui->tablaHorario->setColumnCount(10);

    for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
       ui->tablaHorario->setItem( i, j, new QTableWidgetItem() );
      }
    }
}
