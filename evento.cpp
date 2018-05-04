#include "evento.h"
#include "ui_evento.h"

evento::evento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::evento)
{
    ui->setupUi(this);
}

evento::~evento()
{
    delete ui;
}

void evento::on_pushButton_2_clicked()
{
    hide();
    menu *main = new menu(this);
    main ->show();
}
