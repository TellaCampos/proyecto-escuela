#ifndef CALIFICACION_H
#define CALIFICACION_H
#include "alumnos.h"

#include <QDialog>

namespace Ui {
class calificacion;
}

class calificacion : public QDialog
{
    Q_OBJECT

public:
    explicit calificacion(QWidget *parent = 0);
    ~calificacion();

private slots:
    void on_pushButton_clicked();

private:
    Ui::calificacion *ui;
};

#endif // CALIFICACION_H
