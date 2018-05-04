#ifndef MENU_H
#define MENU_H
#include "alumnos.h"
#include "agenda.h"
#include "materiasmaestro.h"
#include <QDialog>

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
