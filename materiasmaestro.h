#ifndef MATERIASMAESTRO_H
#define MATERIASMAESTRO_H
#include "menu.h"
#include <QDialog>

namespace Ui {
class MateriasMaestro;
}

class MateriasMaestro : public QDialog
{
    Q_OBJECT

public:
    explicit MateriasMaestro(QWidget *parent = 0);
    ~MateriasMaestro();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MateriasMaestro *ui;
};

#endif // MATERIASMAESTRO_H
