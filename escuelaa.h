#ifndef ESCUELAA_H
#define ESCUELAA_H
#include "menu.h"

#include <QMainWindow>

namespace Ui {
class escuelaa;
}

class escuelaa : public QMainWindow
{
    Q_OBJECT

public:
    explicit escuelaa(QWidget *parent = 0);
    ~escuelaa();

private slots:
    void on_pushButton_clicked();

private:
    Ui::escuelaa *ui;
};

#endif // ESCUELAA_H
