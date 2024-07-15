#include "login.h"
#include "check.h"
#include "link.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    info i;
    i.readfile();
    if(i.findmap(ui->usernames->text()) == ui->password->text())
    {
            this->close();
            check *c=new check;
            c->show();
    }
    else
    {
            QMessageBox::warning(this,tr("登录失败"),tr("用户名或密码输入错误！"),QMessageBox::Ok);
            ui->usernames->clear();
            ui->password->clear();
            ui->usernames->setFocus();
    }
}
