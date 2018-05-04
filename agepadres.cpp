#include "agepadres.h"
#include "ui_agepadres.h"

agePadres::agePadres(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agePadres)
{
    ui->setupUi(this);
}

agePadres::~agePadres()
{
    delete ui;
}

void agePadres::on_pushButton_2_clicked()
{
    hide();
    menu *main = new menu(this);
    main ->show();

}

void agePadres::on_pushButton_3_clicked()
{
    hide();
    correo * corr = new correo(this);
    corr ->show();
}
