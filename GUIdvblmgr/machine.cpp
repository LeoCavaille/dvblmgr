#include "machine.h"

Machine::Machine(QListWidget *parent, QString machineName) :
    QListWidgetItem(parent)
{
    listOfCardsDVB = new QList<CardDVB*>() ;
    setMachineName(machineName) ;
    setOnOff(true);
}

void Machine::addCard(CardDVB* cartToBeAdded){
    listOfCardsDVB->append(cartToBeAdded);
}

QList<CardDVB*> *Machine::getListOfCardsDVB(){
    return listOfCardsDVB ;
}

QString Machine::getMachineName() {
    return machineName ;
}

QString Machine::getIpAddress() {
    return ipAddress ;
}

bool Machine::isOnOff() {
    return onOff ;
}

void Machine::setMachineName(QString machineName) {
    this->machineName=machineName ;
    this->setData(Qt::DisplayRole, machineName);
}

void Machine::setIpAddress(QString ipAddress) {
    this->ipAddress=ipAddress ;
    this->setData(Qt::UserRole+1, ipAddress);
}

void Machine::setOnOff(bool onOff) {
    this->onOff=onOff ;
    QString imgPath=onOff?"images/On.png":"images/Off.png";
    this->setData(Qt::DecorationRole, imgPath);
}

Machine::~Machine(){
    delete listOfCardsDVB ;
}
