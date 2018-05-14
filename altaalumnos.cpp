#include "altaalumnos.h"
#include "ui_altaalumnos.h"

altaAlumnos::altaAlumnos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::altaAlumnos)
{
    ui->setupUi(this);
}


altaAlumnos::~altaAlumnos()
{
    delete ui;
}

void altaAlumnos::on_pushButton_clicked()
{
    std::string paterno = ui ->lineEdit ->text().toLocal8Bit().constData();
    std::string materno = ui->lineEdit_2->text().toLocal8Bit().constData();
    std::string nombre = ui->lineEdit_3->text().toLocal8Bit().constData();
    std::string matricula = ui->lineEdit_4->text().toLocal8Bit().constData();
    std::string grupo = ui->spinBox->text().toLocal8Bit().constData();


     std::ofstream db("C:\\Users\\lgvel\\Desktop\\alumnos.txt", std::ios_base::app | std::ios_base::out);

    db << std::endl << paterno << "," << materno << "," << nombre << ","<< matricula << "," << grupo;
    QMessageBox::information(this, "Perfecto", "Se insertó al alumno" );
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->spinBox->setValue(0);
}

void altaAlumnos::on_pushButton_2_clicked()
{
    hide();
    alumnos *even = new alumnos(this);
    even ->show();
}
