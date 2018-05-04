#include "materiasmaestro.h"
#include "ui_materiasmaestro.h"

MateriasMaestro::MateriasMaestro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MateriasMaestro)
{
    ui->setupUi(this);
}

MateriasMaestro::~MateriasMaestro()
{
    delete ui;
}

void MateriasMaestro::on_pushButton_clicked()
{
    hide();
    menu *main = new menu(this);
    main ->show();

}
