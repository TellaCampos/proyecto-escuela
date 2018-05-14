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
    std::vector<std::string> getAlumnos();
    size_t split(std::string txt, std::vector<std::string> &strs, char ch);

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::calificacion *ui;
};

#endif // CALIFICACION_H
