#include "agenmaestros.h"
#include "ui_agenmaestros.h"

agenmaestros::agenmaestros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agenmaestros)
{
    ui->setupUi(this);
}

agenmaestros::~agenmaestros()
{
    delete ui;
}

void agenmaestros::on_pushButton_2_clicked()
{
    hide();
    menu *main = new menu(this);
    main ->show();

}
