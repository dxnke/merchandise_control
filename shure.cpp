#include "shure.h"
#include "ui_shure.h"

shure::shure(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shure)
{
    ui->setupUi(this);
}

shure::~shure()
{
    delete ui;
}

void shure::on_ret_clicked()
{
    this->close();
}
