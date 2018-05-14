#include "agenda.h"
#include "ui_agenda.h"
#include  <QMessageBox>

agenda::agenda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agenda)
{
    ui->setupUi(this);
}

agenda::~agenda()
{
    delete ui;
}

void agenda::on_pushButton_4_clicked()
{
    hide();
    menu *main = new menu(this);
    main ->show();

}

void agenda::on_pushButton_clicked()
{
    hide();
    agePadres *padres = new agePadres(this);
    padres ->show();

}

void agenda::on_pushButton_2_clicked()
{
    hide();
    agenmaestros *masters = new agenmaestros(this);
    masters ->show();

}

void agenda::on_pushButton_3_clicked()
{
    hide();
    evento *even = new evento(this);
    even ->show();

}

void agenda::on_pushButton_5_clicked()
{
    QMessageBox::information(this,"Warning","¿Desea eliminar el evento?");
}


std::vector<std::string> agenda::getAgenda(){
    std::string line;
     std::ifstream myfile ("C:\\Users\\lgvel\\Desktop\\agenda.txt");
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

size_t agenda::split(std::string txt, std::vector<std::string> &strs, char ch)
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






void agenda::on_calendarWidget_clicked(const QDate &date)
{
   QString select = date.toString("dd/MM/yyyy");


   std::vector<std::string> fechas = getAgenda();
   std::vector<std::string> v;
   QStringList myList;
   myList.append(select);

   for( std::string item: fechas ){
       qDebug( item.c_str() );
        split( item, v, ',' );
        if( v[0] == select.toLocal8Bit().constData() ){
           std::string res;
           res.append( v[1] );
           res.append( " - " );
           res.append( v[2] );
            myList.append(  QString::fromStdString(res) );
        }
   }







   QStringListModel* model = new QStringListModel();
   model->setStringList(myList);
   ui->listView->setModel(model);


}
