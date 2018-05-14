#ifndef ALUMNOS_H
#define ALUMNOS_H
#include "calificacion.h"
#include "horario.h"
#include "menu.h"
#include "altaalumnos.h"

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

    void on_pushButton_4_clicked();

    std::vector<std::string> getAlumnos();
    size_t split(std::string txt, std::vector<std::string> &strs, char ch);
    std::vector<std::string> alumnos::getPromedio();

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::alumnos *ui;
};

#endif // ALUMNOS_H
