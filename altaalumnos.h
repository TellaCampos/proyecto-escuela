#ifndef ALTAALUMNOS_H
#define ALTAALUMNOS_H


#include <QDialog>
#include <iostream>
#include <string>
#include <vector>
#include <QStringListModel>
#include <fstream>
#include<QMessageBox>
#include "alumnos.h"

namespace Ui {
class altaAlumnos;
}

class altaAlumnos : public QDialog
{
    Q_OBJECT

public:
    explicit altaAlumnos(QWidget *parent = 0);
    ~altaAlumnos();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::altaAlumnos *ui;
};

#endif // ALTAALUMNOS_H
