#ifndef MACHINE_H
#define MACHINE_H

#include <QListWidgetItem>
#include <QList>
#include <QSize>
#include "carddvb.h"

class Machine : public QListWidgetItem
{
    //Q_OBJECT
public:
    explicit Machine(QListWidget *parent = 0, QString machineName = "");
    ~Machine();
    void addCard(CardDVB* cardToBeAdded) ;
    QList<CardDVB*> *getListOfCardsDVB() ;
    QString getMachineName() ;
    QString getIpAddress() ;
    bool isOnOff() ;
    void setMachineName(QString machineName) ;
    void setIpAddress(QString ipAddress) ;
    void setOnOff(bool onOff) ;

private:
    QList<CardDVB*> *listOfCardsDVB ;
    QString machineName ;
    QString ipAddress ;
    bool onOff ;

};

#endif // MACHINE_H
