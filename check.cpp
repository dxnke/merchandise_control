#include "check.h"
#include "ui_check.h"

check::check(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::check)
{
    ui->setupUi(this);
    stackedWidget = new QStackedWidget;
    stackedWidget->setCurrentWidget(ui->page1);

    connect(ui->find,SIGNAL(clicked(bool)),this,SLOT(on_find_clicked()));
    connect(ui->add,SIGNAL(clicked(bool)),this,SLOT(on_add_clicked()));
    connect(ui->del,SIGNAL(clicked(bool)),this,SLOT(on_del_clicked()));
    connect(ui->print,SIGNAL(clicked(bool)),this,SLOT(on_print_clicked()));
}

check::~check()
{
    delete ui;
}


void check::on_find_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page1);
}

void check::on_add_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page2);
}

void check::on_del_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page3);
}

void check::on_print_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page4);
    Link l;
    l.Linkfile();
    ui->textBrowser->clear();
    Node* p = l.returnhead();
    int count = 1;
    while(p->Getnext()!=nullptr)
    {
        QString str = QString::number(count);
        ui->textBrowser->append(str+" 名称："+p->Getnext()->Getname()+" 产地："+p->Getnext()->Getplace()+" 数量："+p->Getnext()->Getnum());
        count++;
        p = p->Getnext();
    }
}

void check::on_delshure_clicked()
{
    Link l;
    l.Linkfile();
    if(l.JudgeName(ui->deletename->text()))
    {
        l.deletenode(ui->deletename->text());
        l.Savefile();
        QMessageBox::information(this,tr("hello"),tr("商品删除成功"),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(this,tr("错误"),tr("商品不存在"),QMessageBox::Ok);
    }
}

void check::on_findshure_clicked()
{
    Link l;
    l.Linkfile();
  //  l.PrintLink();
    if( l.JudgeName(ui->findname->text()))
    {
        Node* p = l.FindName(ui->findname->text());
        ui->namelabel->clear();
        ui->numlabel->clear();
        ui->placelabel->clear();
        ui->namelabel->setText("名称:"+p->Getname());
        ui->placelabel->setText("产地:"+p->Getplace());
        ui->numlabel->setText("数量:"+p->Getnum());
    }
    else
    {
        QMessageBox::warning(this,tr("查找失败"),tr("无该商品"),QMessageBox::Ok);
        ui->findname->clear();
        ui->namelabel->clear();
        ui->numlabel->clear();
        ui->placelabel->clear();
        ui->namelabel->setText("名称:");
        ui->placelabel->setText("产地:");
        ui->numlabel->setText("数量:");
    }
}

void check::on_addshure_clicked()
{
    Link l;
    l.Linkfile();
    if(!l.JudgeName(ui->addname->text()))
    {
        l.InsertLink(ui->addname->text(),ui->addplace->text(),ui->addnum->text());
        l.Savefile();
        QMessageBox::information(this,tr("hello"),tr("商品添加成功"),QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(this,tr("错误"),tr("商品已存在"),QMessageBox::Ok);
    }

}
