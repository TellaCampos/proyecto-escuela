#ifndef DIALOGALTA_H
#define DIALOGALTA_H

#include <QDialog>

namespace Ui {
class DialogAlta;
}

class DialogAlta : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAlta(QWidget *parent = 0);
    ~DialogAlta();

private:
    Ui::DialogAlta *ui;
};

#endif // DIALOGALTA_H
