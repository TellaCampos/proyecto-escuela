#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);


    // Nombre
    std::vector<std::string> data = this -> datos();
    std::vector<std::string> v;
    for( std::string item: data )
        qDebug( item.c_str() );

    this -> split( data[ 0 ], v, ',' );
    ui->label->setText( QString::fromStdString( v[ 2 ] ) );


    // Tutorados
    std::vector<std::string> alum = getAlumnos();
    std::vector<std::string> f;
    QStringList myList;


    for( std::string item: alum ){
        qDebug( item.c_str() );
         split( item, f, ',' );
         if( v[3] == f[4]){
             std::string res;
             res.append( f[0] );
             res.append( " " );
             res.append( f[1] );
             res.append( " " );
             res.append( f[2] );
             res.append( " - Matrícula ");
             res.append( f[3] );
             res.append( " - grupo " );
             res.append( f[4] );
              myList.append(  QString::fromStdString(res) );
         }

    }


    QStringListModel* model = new QStringListModel();
    model->setStringList(myList);
    ui->tutorados->setModel(model);

// Notas

    std::vector<std::string> nota = notas();
    std::vector<std::string> k;
    QStringList misnotas;


    for( std::string item: nota ){
        misnotas.append( QString::fromStdString( item ) );

    }

    QStringListModel* modelNotas = new QStringListModel();
    modelNotas->setStringList(misnotas);
    ui->listView_2->setModel(modelNotas);


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

std::vector<std::string> menu::notas(){
    std::string line;
     std::ifstream myfile ("C:\\Users\\lgvel\\Desktop\\notas.txt");
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

std::vector<std::string> menu::getAlumnos(){
    std::string line;
     std::ifstream myfile ("C:\\Users\\lgvel\\Desktop\\alumnos.txt");
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
            QMessageBox::information(this, "Error", " Error con la agenda ");
            std::vector<std::string> f;
            return f;
     }
}


void menu::on_pushButton_4_clicked()
{
    hide();
    escuelaa *esc = new escuelaa(this);
    esc ->show();
}

void menu::on_pushButton_5_clicked()
{
    hide();
    agregarNota *esc = new agregarNota(this);
    esc ->show();
}
