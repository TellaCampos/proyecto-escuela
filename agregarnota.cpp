#include "agregarnota.h"
#include "ui_agregarnota.h"

agregarNota::agregarNota(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agregarNota)
{
    ui->setupUi(this);
}

agregarNota::~agregarNota()
{
    delete ui;
}

void agregarNota::on_pushButton_clicked()
{
    std::string data = ui->textEdit->toPlainText().toLocal8Bit().constData();
    std::ofstream db("C:\\Users\\lgvel\\Desktop\\notas.txt", std::ios_base::app | std::ios_base::out);

   db << std::endl << data;
   QMessageBox::information(this, "Perfecto", "Se agrego su nota" );

   hide();
   menu *esc = new menu(this);
   esc ->show();


    qDebug( data.c_str());
}
