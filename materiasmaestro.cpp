#include "materiasmaestro.h"
#include "ui_materiasmaestro.h"

MateriasMaestro::MateriasMaestro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MateriasMaestro)
{
    ui->setupUi(this);

    std::vector<std::string> data = this -> datos();
    std::vector<std::string> v;
    for( std::string item: data )
        qDebug( item.c_str() );

    this -> split( data[ 0 ], v, ',' );

    std::vector<std::string> hora = horario();
    std::vector<std::string> f;

    for( auto item: hora ){
        split( item, f, ',' );
        if( v[0]==f[0]){

            ui->tableWidget->setItem(  std::atoi( f[4].c_str() )  , std::atoi( f[3].c_str() )  , new QTableWidgetItem( f[1].c_str() ) );
           //qDebug( j );
        }
    }


}

MateriasMaestro::~MateriasMaestro()
{
    delete ui;
}

void MateriasMaestro::on_pushButton_clicked()
{
    hide();
    menu *main = new menu(this);
    main ->show();

}

void MateriasMaestro::on_pushButton_2_clicked()
{
    hide();
    altaMateria *main = new altaMateria(this);
    main ->show();
}



std::vector<std::string> MateriasMaestro::datos(){
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


std::vector<std::string> MateriasMaestro::horario(){
    std::string line;
     std::ifstream myfile ("C:\\Users\\lgvel\\Desktop\\horario.txt");
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

size_t MateriasMaestro::split(std::string txt, std::vector<std::string> &strs, char ch)
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

void MateriasMaestro::on_tableWidget_cellClicked(int row, int column)
{


    std::vector<std::string> hora = horario();
    std::vector<std::string> f;

    for( auto item: hora ){
        split( item, f, ',' );
        if(  std::atoi( f[3].c_str() ) ==column &&  std::atoi( f[4].c_str() ) ==row){
            ui->lineEdit->setText( QString::fromStdString( f[5].c_str() ));
            ui->lineEdit_2->setText( QString::fromStdString( f[2].c_str() ));

          // qDebug( f[1].c_str() );
        }
    }
}
