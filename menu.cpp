#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    std::vector<std::string> data = this -> datos();
    std::vector<std::string> v;
    for( std::string item: data )
        qDebug( item.c_str() );

    this -> split( data[ 0 ], v, ',' );
    ui->label->setText( QString::fromStdString( v[ 2 ] ) );
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
    hide();
    alumnos *ventanaalumno = new alumnos(this);
    ventanaalumno ->show();

}

void menu::on_pushButton_2_clicked()
{
    hide();
    agenda *agendageneral = new agenda(this);
    agendageneral ->show();

}

void menu::on_pushButton_3_clicked()
{
    hide();
    MateriasMaestro *materias = new MateriasMaestro(this);
    materias ->show();


}

std::vector<std::string> menu::datos(){
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

size_t menu::split(std::string txt, std::vector<std::string> &strs, char ch)
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
