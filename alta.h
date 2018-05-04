#ifndef ALTA_H
#define ALTA_H

#include <QDialog>

namespace Ui {
class alta;
}

class alta : public QDialog
{
    Q_OBJECT

public:
    explicit alta(QWidget *parent = 0);
    ~alta();

private slots:


private:
    Ui::alta *ui;
};

#endif // ALTA_H
