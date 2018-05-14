    #ifndef AGEPADRES_H
#define AGEPADRES_H
#include "menu.h"
#include <QDialog>
#include "correo.h"
#include "agenda.h"


namespace Ui {
class agePadres;
}

class agePadres : public QDialog
{
    Q_OBJECT

public:
    explicit agePadres(QWidget *parent = 0);
    ~agePadres();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    size_t split(std::string txt, std::vector<std::string> &strs, char ch);


private:
    Ui::agePadres *ui;
};

#endif // AGEPADRES_H
