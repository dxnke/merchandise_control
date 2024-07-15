#ifndef SHURE_H
#define SHURE_H

#include <QDialog>

namespace Ui {
class shure;
}

class shure : public QDialog
{
    Q_OBJECT

public:
    explicit shure(QWidget *parent = nullptr);
    ~shure();

private slots:
    void on_ret_clicked();

private:
    Ui::shure *ui;
};

#endif // SHURE_H
