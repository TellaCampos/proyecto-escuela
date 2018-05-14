#ifndef AGENMAESTROS_H
#define AGENMAESTROS_H
#include "menu.h"

#include <QDialog>

namespace Ui {
class agenmaestros;
}

class agenmaestros : public QDialog
{
    Q_OBJECT

public:
    explicit agenmaestros(QWidget *parent = 0);
    ~agenmaestros();

private slots:
    void on_pushButton_2_clicked();
        size_t split(std::string txt, std::vector<std::string> &strs, char ch);

        void on_pushButton_clicked();

private:
    Ui::agenmaestros *ui;
};

#endif // AGENMAESTROS_H
