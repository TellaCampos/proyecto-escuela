#include "escuelaa.h"
#include "ui_escuelaa.h"

escuelaa::escuelaa(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::escuelaa)
{
    ui->setupUi(this);
}

escuelaa::~escuelaa()
{
    delete ui;
}

void escuelaa::on_pushButton_clicked()
{
    hide();
    menu *main = new menu(this);
    main -> show();
}
