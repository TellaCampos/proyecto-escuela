#include "altaprofesores.h"
#include "ui_altaprofesores.h"

altaprofesores::altaprofesores(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::altaprofesores)
{
    ui->setupUi(this);
}

altaprofesores::~altaprofesores()
{
    delete ui;
}
