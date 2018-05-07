#ifndef ESCUELAA_H
#define ESCUELAA_H
#include "menu.h"
#include "altaprofesores.h"

#include <QMainWindow>
#include <iostream>
#include <fstream>
#include <string>
#include<QMessageBox>
#include <QString>
#include <sstream>

namespace Ui {
class escuelaa;
}

class escuelaa : public QMainWindow
{
    Q_OBJECT

public:
    explicit escuelaa(QWidget *parent = 0);
    ~escuelaa();

private slots:
    void on_pushButton_clicked();
    void verifica(int);
    std::vector<std::string> usuarios();

private:
    Ui::escuelaa *ui;

};

#endif // ESCUELAA_H
