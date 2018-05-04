#ifndef ALTAPROFESORES_H
#define ALTAPROFESORES_H

#include <QMainWindow>

namespace Ui {
class altaprofesores;
}

class altaprofesores : public QMainWindow
{
    Q_OBJECT

public:
    explicit altaprofesores(QWidget *parent = 0);
    ~altaprofesores();

private:
    Ui::altaprofesores *ui;
};

#endif // ALTAPROFESORES_H
