#include "alumnos.h"
#include "ui_alumnos.h"

alumnos::alumnos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alumnos)
{
    ui->setupUi(this);


    std::vector<std::string> alum = getAlumnos();
    std::vector<std::string> v;
    QStringList myList;


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

alumnos::~alumnos()
{
    delete ui;
}

void alumnos::on_alumnos_accepted()
{

}

void alumnos::on_pushButton_clicked()
{
    hide();
    calificacion *cali = new calificacion(this);
    cali ->show();

}

void alumnos::on_pushButton_2_clicked()
{
    hide();
    MateriasMaestro *hora = new MateriasMaestro(this);
    hora ->show();

}

void alumnos::on_pushButton_3_clicked()
{
    hide();
    menu *main = new menu(this);
    main ->show();

}

void alumnos::on_pushButton_4_clicked()
{
    hide();
    altaAlumnos *main = new altaAlumnos(this);
    main ->show();
}


std::vector<std::string> alumnos::getAlumnos(){
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


std::vector<std::string> alumnos::getPromedio(){
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
size_t alumnos::split(std::string txt, std::vector<std::string> &strs, char ch)
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


void alumnos::on_listView_clicked(const QModelIndex &index)
{
    //for( auto item: index )
      //     qDebug( item.data().toString().toLocal8Bit().constData() );
    qDebug( index.data().toString().toLocal8Bit().constBegin() );

    std::string req = index.data().toString().toLocal8Bit().constData();


    std::vector<std::string> alumB = getAlumnos();
    std::vector<std::string> cali = getPromedio();
    std::vector<std::string> v;
    std::vector<std::string> res_;
    std::vector<std::string> resF;
    std::string alc;

    split( req, res_, '-');
    split( res_[0], resF, ' ');


    for( std::string item: alumB ){
        qDebug( item.c_str() );
         split( item, v, ',' );
         if( v[0]==resF[0] && v[1] == resF[1] && v[2]== resF[2]){
             for( std::string itemC: cali ){
                 split( itemC, res_, ',');
                 if( res_[0]==v[3] )
                       ui->lineEdit_3->setText(QString::fromStdString( res_[1] ) );
                 else
                     ui->lineEdit_3->setText( "S/C" );
             }
             alc.clear();
             alc.append( v[0] );
             alc.append( " " );
             alc.append( v[1] );
             alc.append( " " );
             alc.append( v[2] );
             ui->lineEdit->setText( QString::fromStdString(alc) );
             ui->lineEdit_2->setText( QString::fromStdString( v[3] ) );
         }
    }

}
