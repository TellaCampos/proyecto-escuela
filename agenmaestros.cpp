#include "agenmaestros.h"
#include "ui_agenmaestros.h"

agenmaestros::agenmaestros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agenmaestros)
{
    ui->setupUi(this);
}

agenmaestros::~agenmaestros()
{
    delete ui;
}

void agenmaestros::on_pushButton_2_clicked()
{
    hide();
    menu *main = new menu(this);
    main ->show();

}

size_t agenmaestros::split(std::string txt, std::vector<std::string> &strs, char ch)
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



void agenmaestros::on_pushButton_clicked()
{

    std::vector<std::string> v;
    split(ui ->fecha->text().toLocal8Bit().constData(), v, ' ' );
    std::string fecha = v[0].c_str();
    std::string evento = ui ->textEdit->toPlainText().toLocal8Bit().constData();

    std::ofstream db("C:\\Users\\lgvel\\Desktop\\agenda.txt", std::ios_base::app | std::ios_base::out);

    db << std::endl << fecha << "," << evento << "," << "Maestros";
    QMessageBox::information(this, "Perfecto", "Se insertó su evento" );

    hide();
    agenda * retr = new agenda(this);
    retr ->show();

}
