#ifndef CHECK_H
#define CHECK_H

#include <QDialog>
#include <QStackedWidget>
#include <QMessageBox>
#include <QWidget>
#include<QString>
#include<QList>
#include<QDebug>
#include<string.h>
#include<QByteArray>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>

#include "link.h"

namespace Ui {
class check;
}

class check : public QDialog
{
    Q_OBJECT

public:
    explicit check(QWidget *parent = nullptr);
    ~check();

private slots:

    void on_find_clicked();

    void on_add_clicked();

    void on_del_clicked();

    void on_print_clicked();

    void on_delshure_clicked();

    void on_findshure_clicked();

    void on_addshure_clicked();

private:
    Ui::check *ui;
    QStackedWidget *stackedWidget;
};

#endif // CHECK_H
