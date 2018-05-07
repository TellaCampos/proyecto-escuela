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

std::vector<std::string> escuelaa::usuarios(){
    std::string line;
     std::ifstream myfile ("C:\\Users\\lgvel\\Desktop\\users.txt");
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

void escuelaa::on_pushButton_clicked(){

    if( ui ->user -> text() == "admin" && ui -> pass -> text() == "password"){
        altaprofesores *DarAlta = new altaprofesores( this );
        this->hide();
        DarAlta -> show();


    }else{
       this -> verifica( 0 );
    }



}

size_t split(std::string txt, std::vector<std::string> &strs, char ch)
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


void escuelaa::verifica( int pos ){
    std::string text = std::to_string(pos);
   qDebug( text.c_str() );
    std::vector<std::string> users = usuarios();
    std::vector<std::string> v;
    for( std::string item: users )
        qDebug( item.c_str() );

    split( users[ pos ], v, ' ' );



    if( ui -> user -> text().toLocal8Bit().constData() == v [ 0 ] && ui -> pass -> text().toLocal8Bit().constData() == v[ 1 ] ){
        QMessageBox::information(this, "Login", " inicio de sesión exitoso ");
        hide();
        menu *main = new menu(this);
        main -> show();

    }else{
        if( users.size()  > pos )
         verifica( ++pos );
    }
}
