#include "xmlhelper.h"
#include <iostream>
#include <QDebug>

using namespace std;

XMLHelper::XMLHelper()
{
}

QStringList XMLHelper::getValueFromString(QString xml)
{
    QDomDocument doc;
    QString *errorStr;
    QStringList list;
    int errorLine;
    int errorCol;
    if(!doc.setContent(xml,true,errorStr,&errorLine,&errorCol)) {
        qDebug () << errorStr << errorLine << errorCol;
        qDebug() << xml;
    } else {
        QDomNode n = doc.firstChild();
        list = getText(n,list);
    }
    return list;
}

QStringList XMLHelper::getText(QDomNode node,QStringList list)
{
    if(node.hasChildNodes()){
        QDomNodeList nodeList = node.childNodes();
        for(int i=0;i<nodeList.size();i++){
            QDomNode child = nodeList.at(i);
            list = getText(child,list);
        }
    }else{
        list << node.nodeValue();
    }
    return list;
}
