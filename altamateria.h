#ifndef ALTAMATERIA_H
#define ALTAMATERIA_H

#include <QDialog>
#include "materiasmaestro.h"
#include <iostream>
#include <fstream>
#include <string>
#include<QMessageBox>
#include <QString>
#include <sstream>
namespace Ui {
class altaMateria;
}

class altaMateria : public QDialog
{
    Q_OBJECT

public:
    explicit altaMateria(QWidget *parent = 0);
    ~altaMateria();

private slots:

    std::vector<std::string> datos();
    size_t split(std::string txt, std::vector<std::string> &strs, char ch);
    void on_pushButton_clicked();

private:
    Ui::altaMateria *ui;
};

#endif // ALTAMATERIA_H
