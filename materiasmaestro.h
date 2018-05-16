#ifndef MATERIASMAESTRO_H
#define MATERIASMAESTRO_H
#include "menu.h"
#include <QDialog>
#include "altamateria.h"

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

    void on_pushButton_2_clicked();

    std::vector<std::string> datos();

    std::vector<std::string> horario();
    size_t split(std::string txt, std::vector<std::string> &strs, char ch);

    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::MateriasMaestro *ui;
};

#endif // MATERIASMAESTRO_H
