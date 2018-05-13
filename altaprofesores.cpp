#include "altaprofesores.h"
#include "ui_altaprofesores.h"

altaprofesores::altaprofesores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::altaprofesores)
{
    ui->setupUi(this);
}

altaprofesores::~altaprofesores()
{
    delete ui;
}

void altaprofesores::on_pushButton_clicked()
{
   std::string user =  ui ->lineEdit ->text().toLocal8Bit().constData() ;
   std::string pass = ui ->lineEdit_2 -> text().toLocal8Bit().constData();
   std::string nombre = ui->lineEdit_3 ->text().toLocal8Bit().constData();
   std::string grupo = ui->spinBox->text().toLocal8Bit().constData();

   if(std::count(user.begin(), user.end(), ' ') > 0 )
       QMessageBox::information(this, "Error", " Error con su usuario ");
   else{
       if( std::count(pass.begin(), pass.end(), ' ') > 0 )
           QMessageBox::information(this, "Error", " Error con su contraseña ");
       else{
           if(std::count(nombre.begin(), nombre.end(), ',') > 0){
                QMessageBox::information(this, "Error", " Error con su nombre ");
           }else{
               std::ofstream db("C:\\Users\\lgvel\\Desktop\\users.txt", std::ios_base::app | std::ios_base::out);

               db << std::endl << user << "," << pass << "," << nombre << "," << grupo;
               QMessageBox::information(this, "Perfecto", "Se insertó su profesor" );
           }

       }


   }



}

void altaprofesores::on_pushButton_2_clicked()
{
    hide();
    escuelaa *main = new escuelaa(this);
    main -> show();
}
