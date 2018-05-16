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
#include"escuelaa.h"
#include "agregarnota.h"
#include <QPixmap>
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
    std::vector<std::string> getAlumnos();

    std::vector<std::string> datos();
        std::vector<std::string> notas();
    size_t split(std::string txt, std::vector<std::string> &strs, char ch);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
