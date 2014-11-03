#ifndef BUG_H
#define BUG_H

#include <QStringList>

class Bug
{
public:
    static Bug * createBug(QStringList,QStringList);
    static Bug * getEmpty();
    QString id;
    QString sev;
    QString pri;
    QString assignee;
    QString status;
    QString resolution;
    QString type;
    QString des;
    QStringList head;
    QStringList value;
private :
    Bug();
};

#endif // BUG_H
