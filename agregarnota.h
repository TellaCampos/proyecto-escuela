#ifndef AGREGARNOTA_H
#define AGREGARNOTA_H

#include <QDialog>
#include "menu.h"

namespace Ui {
class agregarNota;
}

class agregarNota : public QDialog
{
    Q_OBJECT

public:
    explicit agregarNota(QWidget *parent = 0);
    ~agregarNota();

private slots:
    void on_pushButton_clicked();

private:
    Ui::agregarNota *ui;
};

#endif // AGREGARNOTA_H
