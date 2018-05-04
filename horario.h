#ifndef HORARIO_H
#define HORARIO_H
#include "menu.h"
#include <QDialog>

namespace Ui {
class horario;
}

class horario : public QDialog
{
    Q_OBJECT

public:
    explicit horario(QWidget *parent = 0);
    ~horario();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::horario *ui;
};

#endif // HORARIO_H
