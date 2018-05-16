#include "altamateria.h"
#include "ui_altamateria.h"

altaMateria::altaMateria(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::altaMateria)
{
    ui->setupUi(this);
}

altaMateria::~altaMateria()
{
    delete ui;
}

void altaMateria::on_pushButton_clicked()
{

    std::vector<std::string> data = this -> datos();
    std::vector<std::string> v;
    for( std::string item: data )
        qDebug( item.c_str() );

    this -> split( data[ 0 ], v, ',' );



    std::string materia =  ui->lineEdit->text().toLocal8Bit().constData();
    std::string seccion = ui->lineEdit_2->text().toLocal8Bit().constData();
    std::string salon = ui->lineEdit_3->text().toLocal8Bit().constData();
    int dia = ui->comboBox->currentIndex();
    int hora = ui->comboBox_2->currentIndex();
   // qDebug( seccion.c_str() );
    std::ofstream db("C:\\Users\\lgvel\\Desktop\\horario.txt", std::ios_base::app | std::ios_base::out);

    db << std::endl << v[0] << "," << materia << "," << seccion << "," << dia << ","<< hora << ","<< salon;
    db.close();
    QMessageBox::information( this, "Correcto", "Se agrego su materia");

    hide();
    MateriasMaestro *main = new MateriasMaestro(this);
    main -> show();


}


std::vector<std::string> altaMateria::datos(){
    std::string line;
     std::ifstream myfile ("C:\\Users\\lgvel\\Desktop\\data.txt");
     std::vector<std::string> array;
     if (myfile.is_open())
     {
       while ( getline( myfile, line ) )
       {
         array.push_back( line );
         qDebug( line.c_str());
       }
       myfile.close();
       return array;
     }else{
            QMessageBox::information(this, "Error", " Error con los usuarios ");
            std::vector<std::string> f;
            return f;
     }
}

size_t altaMateria::split(std::string txt, std::vector<std::string> &strs, char ch)
{

    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();

    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );
    return strs.size();
}
