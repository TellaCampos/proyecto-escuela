#include "dialogalta.h"
#include "ui_dialogalta.h"

DialogAlta::DialogAlta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAlta)
{
    ui->setupUi(this);
}

DialogAlta::~DialogAlta()
{
    delete ui;
}
