#include "calificacion.h"
#include "ui_calificacion.h"

calificacion::calificacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calificacion)
{
    ui->setupUi(this);

    std::vector<std::string> alum = getAlumnos();
    std::vector<std::string> v;
    QStringList myList;

    matricula = "";
    for( std::string item: alum ){
        qDebug( item.c_str() );
         split( item, v, ',' );

            std::string res;
            res.append( v[0] );
            res.append( " " );
            res.append( v[1] );
            res.append( " " );
            res.append( v[2] );
            res.append( " - Matrícula ");
            res.append( v[3] );
            res.append( " - grupo " );
            res.append( v[4] );
             myList.append(  QString::fromStdString(res) );
    }


    QStringListModel* model = new QStringListModel();
    model->setStringList(myList);
    ui->listView->setModel(model);

}


std::vector<std::string> calificacion::getPromedio(){
    std::string line;
     std::ifstream myfile ("C:\\Users\\lgvel\\Desktop\\calificaciones.txt");
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

std::vector<std::string> calificacion::getAlumnos(){
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

size_t calificacion::split(std::string txt, std::vector<std::string> &strs, char ch)
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


calificacion::~calificacion()
{
    delete ui;
}

void calificacion::on_pushButton_clicked()
{
    hide();
    alumnos *atras = new alumnos(this);
    atras ->show();

}

void calificacion::on_listView_clicked(const QModelIndex &index)
{
   std::vector<std::string> r;
   std::vector<std::string> l;
   std::vector<std::string> v;
   bool flag;
   std::vector<std::string> prom = getPromedio();
    std::string req = index.data().toString().toLocal8Bit().constData();
    split(req, r, '-'); //Se recupera del viewTable

    split(r[1], l, ' '); //Se divide matrícula
    qDebug( l[2].c_str() ); //matrícula
    matricula = l[2];
    flag = true;
    for( auto item : prom ){
        if( flag )
            ui->materias->setValue( 0 );
        split( item, v, ',');
        if( matricula == v[0] ){
            ui->materias->setValue( atoi( v[1].c_str() ));
            flag = false;
        }
    }


    ui->label_6->setText( QString::fromStdString( r[0]) );
    ui->label_7->setText( QString::fromStdString( r[1] ));

}

void calificacion::on_pushButton_2_clicked()
{
    std::ofstream db("C:\\Users\\lgvel\\Desktop\\calificaciones.txt", std::ios_base::app | std::ios_base::out);


    if( matricula != "" ){
         db << std::endl << matricula << "," <<  ui->materias->value();
         QMessageBox::information( this, "Aceptar", "Se cambió de calificación") ;
    }else{
        QMessageBox::information(this, "Error", "No seleccionó ningún alumno");
    }
}
