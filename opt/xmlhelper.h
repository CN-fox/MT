#ifndef XMLHELPER_H
#define XMLHELPER_H
#include<QStringList>
#include<QDomDocument>

class XMLHelper
{
public:
    static QStringList getValueFromString(QString xml);
private:
    XMLHelper();
    static QStringList getText(QDomNode ,QStringList);
};

#endif // XMLHELPER_H
