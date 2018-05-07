#ifndef ALUMNOS_H
#define ALUMNOS_H
#include "calificacion.h"
#include "horario.h"
#include "menu.h"

#include <QDialog>

namespace Ui {
    class alumnos;
}

class alumnos : public QDialog
{
    Q_OBJECT

public:
    explicit alumnos(QWidget *parent = 0);
    ~alumnos();

private slots:
    void on_alumnos_accepted();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::alumnos *ui;
};

#endif // ALUMNOS_H
