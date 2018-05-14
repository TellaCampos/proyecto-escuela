#include "agepadres.h"
#include "ui_agepadres.h"

agePadres::agePadres(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::agePadres)
{
    ui->setupUi(this);
}

agePadres::~agePadres()
{
    delete ui;
}

void agePadres::on_pushButton_2_clicked()
{
    hide();
    menu *main = new menu(this);
    main ->show();

}

void agePadres::on_pushButton_3_clicked()
{
    hide();
    correo * corr = new correo(this);
    corr ->show();
}


size_t agePadres::split(std::string txt, std::vector<std::string> &strs, char ch)
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


void agePadres::on_pushButton_clicked()
{
    std::vector<std::string> v;
    split(ui ->fecha->text().toLocal8Bit().constData(), v, ' ' );
    std::string fecha = v[0].c_str();
    std::string evento = ui ->textEdit->toPlainText().toLocal8Bit().constData();

    std::ofstream db("C:\\Users\\lgvel\\Desktop\\agenda.txt", std::ios_base::app | std::ios_base::out);

    db << std::endl << fecha << "," << evento << "," << "Padres";
    QMessageBox::information(this, "Perfecto", "Se insertó su evento" );

    hide();
    agenda * retr = new agenda(this);
    retr ->show();
}
