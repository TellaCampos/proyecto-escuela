#ifndef ALTAPROFESORES_H
#define ALTAPROFESORES_H

#include <QDialog>
#include <iostream>
#include <fstream>
#include <string>
#include<QMessageBox>
#include <QString>
#include "escuelaa.h"

namespace Ui {
class altaprofesores;
}

class altaprofesores : public QDialog
{
    Q_OBJECT

public:
    explicit altaprofesores(QWidget *parent = 0);
    ~altaprofesores();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::altaprofesores *ui;
};

#endif // ALTAPROFESORES_H
