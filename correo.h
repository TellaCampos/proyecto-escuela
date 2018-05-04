#ifndef CORREO_H
#define CORREO_H
#include "menu.h"
#include <QDialog>

namespace Ui {
class correo;
}

class correo : public QDialog
{
    Q_OBJECT

public:
    explicit correo(QWidget *parent = 0);
    ~correo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::correo *ui;
};

#endif // CORREO_H
