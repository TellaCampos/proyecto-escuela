#include "alta.h"
#include "ui_alta.h"
#include  <QMessageBox>

alta::alta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alta)
{
    ui->setupUi(this);
}

alta::~alta()
{
    delete ui;
}
