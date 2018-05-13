#ifndef MENU_H
#define MENU_H
#include "alumnos.h"
#include "agenda.h"
#include "materiasmaestro.h"
#include <QMainWindow>
#include <iostream>
#include <fstream>
#include <string>
#include<QMessageBox>
#include <QString>
#include <sstream>

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

    std::vector<std::string> datos();
    size_t split(std::string txt, std::vector<std::string> &strs, char ch);

private:
    Ui::menu *ui;
};

#endif // MENU_H
