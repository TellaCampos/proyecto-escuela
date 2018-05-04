#ifndef AGENDA_H
#define AGENDA_H
#include "agenmaestros.h"
#include "agepadres.h"
#include "evento.h"
#include "menu.h"
#include <QDialog>

namespace Ui {
class agenda;
}

class agenda : public QDialog
{
    Q_OBJECT

public:
    explicit agenda(QWidget *parent = 0);
    ~agenda();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::agenda *ui;
};

#endif // AGENDA_H
