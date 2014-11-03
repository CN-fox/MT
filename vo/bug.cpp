#include "bug.h"|

Bug::Bug()
{
}

Bug * Bug::createBug(QStringList head, QStringList value)
{

    if(head.size() == value.size() && head.size() >0){

    }else{
        value.removeOne("Resol");
    }
    Bug *bug = new Bug();
    bug->head = head;
    bug->value = value;
    bug->id = value.at(head.indexOf("ID"));
    bug->sev = value.at(head.indexOf("Sev"));
    bug->type = value.at(head.indexOf("Type"));
    bug->pri = value.at(head.indexOf("Pri"));
    return bug;
}

Bug * Bug::getEmpty()
{
    return new Bug();
}
