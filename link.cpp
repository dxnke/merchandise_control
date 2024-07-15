#include "link.h"

void info::readfile()
{
    int count = 1;
    QFile file("C:\\Users\\Administrator\\Desktop\\rubbish\\merchandise_control\\data.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!file.atEnd())
        {
            QByteArray line = file.readLine();
            QString str(line);
            str = str.left((str.size()-1));
            if(count%2!=0)
            {
                QByteArray line = file.readLine();
                QString str1(line);
                str1 = str1.left((str1.size()-1));
                m1.insert(std::pair<QString,QString>(str,str1));
                count++;
            }
            count++;
         //   qDebug() << str<<count;
        }
    }
    file.close();
}

QString info::findmap(QString s)
{
    return m1.find(s)->second;
}

Node::Node(QString y,QString z,QString n)
{
    name = y;
    place = z;
    num = n;
    next = nullptr;
}
QString Node::Getnum()
{
    return num;
}
QString Node::Getname()
{
    return name;
}
QString Node::Getplace()
{
    return place;
}
Node* Node::Getnext()
{
    return next;
}
void Node::Setnext(Node* p)
{
    next = p;
}
Link::Link()
{
    head=new Node("head","head","head");
}
void Link::InsertLink( QString y, QString z, QString n)
{
        Node* s = new Node(y,z,n);
        Node* hp = head;
        while(hp->Getnext() != nullptr)
        {
            hp = hp->Getnext();
        }
        hp->Setnext(s);
}
void Link::Linkfile()
{

    QFile file("C:\\Users\\Administrator\\Desktop\\rubbish\\merchandise_control\\commodity.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!file.atEnd())
        {
            QByteArray line1 = file.readLine();
            QString str1(line1);
            str1 = str1.left((str1.size()-1));
            QByteArray line2 = file.readLine();
            QString str2(line2);
            str2 = str2.left((str2.size()-1));
            QByteArray line3 = file.readLine();
            QString str3(line3);
            str3 = str3.left((str3.size()-1));
            InsertLink(str1,str2,str3);

         }
         //   qDebug() << str<<count;
    }
    file.close();
}
void Link::PrintLink()
{
    Node* hp = head;
    while(hp->Getnext()!=nullptr)
    {
        qDebug() <<hp->Getnext()->Getname()<<hp->Getnext()->Getplace()<<hp->Getnext()->Getnum();
        hp=hp->Getnext();
    }
}
Node* Link::FindName(QString x)
{
    Node* hp = head;
    while(hp->Getnext()!=nullptr)
    {
        if(hp->Getname() == x)
        {
            break;
        }
        hp=hp->Getnext();
    }
   // qDebug()<<hp->Getname()<<hp->Getplace()<<hp->Getnum();
    return hp;
}

bool Link::JudgeName(QString x)
{
    Node* hp = head;
    while(hp->Getnext()!=nullptr)
    {
        if(hp->Getname() == x)
        {
            break;
        }
        hp=hp->Getnext();
    }
    if(hp->Getname() == x)
            return true;
    else
            return false;
}
void Link::Savefile()
{
    Node* hp = head;
    QFile file("C:\\Users\\Administrator\\Desktop\\rubbish\\merchandise_control\\commodity.txt");
    QTextStream in(&file);
    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate))
    {
        while(hp->Getnext()!=nullptr)
        {
            std::string str1 = hp->Getnext()->Getname().toStdString();
            const char* line1 = str1.c_str();
            std::string str2 = hp->Getnext()->Getplace().toStdString();
            const char* line2 = str2.c_str();
            std::string str3 = hp->Getnext()->Getnum().toStdString();
            const char* line3 = str3.c_str();
            file.write(line1);
            file.write("\n");
            file.write(line2);
            file.write("\n");
            file.write(line3);
            file.write("\n");
            hp = hp->Getnext();
        }
    }
    file.close();
}

void Link::deletenode(QString qs)
{
    if(JudgeName(qs))
    {
        Node* hp = head;
        while(hp->Getnext()!=nullptr)
        {
            if(hp->Getnext()->Getname() == qs)
            {
                break;
            }
            hp=hp->Getnext();
        }
        Node* p = hp->Getnext();
        hp->Setnext(p->Getnext());
        delete p;
    }
    else
    {
        return;
    }
}

Node* Link::returnhead()
{
    return head;
}
