#ifndef EVENTO_H
#define EVENTO_H
#include "menu.h"
#include <QDialog>

namespace Ui {
class evento;
}

class evento : public QDialog
{
    Q_OBJECT

public:
    explicit evento(QWidget *parent = 0);
    ~evento();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::evento *ui;
};

#endif // EVENTO_H
