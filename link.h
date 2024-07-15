#ifndef LINK_H
#define LINK_H
#include<QString>
#include<QTextStream>
#include<QFile>
#include<QDebug>
#include<iostream>
#include<map>
#include<QTextCodec>//解决中文编码格式问题

class info
{
public:
    void readfile();
    QString findmap(QString s);
private:
    std::map<QString,QString> m1;
};

class Node
{
public:
    Node(QString y,QString z,QString n);
    QString Getname();
    QString Getplace();
    QString Getnum();
    Node* Getnext();
    void Setnext(Node* p);
private:
    QString name;
    QString place;
    QString num;
    Node* next;
};

class Link
{
public:
    Link();
    void InsertLink(QString y,QString z,QString n);
    void Linkfile();
    void Savefile();
    Node* FindName(QString x);
    bool JudgeName(QString x);
    void PrintLink();
    void deletenode(QString qs);
    Node* returnhead();
private:
    Node* head;
};

#endif // LINK_H
