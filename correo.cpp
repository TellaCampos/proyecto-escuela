#include "correo.h"
#include "ui_correo.h"

correo::correo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::correo)
{
    ui->setupUi(this);
}

correo::~correo()
{
    delete ui;
}

void correo::on_pushButton_clicked()
{
    hide();
    menu *main = new menu(this);
    main ->show();

}
