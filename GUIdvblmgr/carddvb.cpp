#include "carddvb.h"

CardDVB::CardDVB(QListWidget *parent, QString cardID) :
    QListWidgetItem(parent)
{
    setCardID(cardID);
    setOnOff(true);
    setSizeHint(QSize(100, 50));
    setBackgroundColor(QColor(210, 195, 200));
}


QString CardDVB::getCardID() {
    return cardID ;
}

QString CardDVB::getDescription() {
    return description ;
}

bool CardDVB::isOnOff() {
    return onOff ;
}

void CardDVB::setCardID(QString cardID) {
    this->cardID=cardID ;
    this->setData(Qt::DisplayRole, cardID);
}

void CardDVB::setDescription(QString description) {
    this->description=description ;
    this->setData(Qt::UserRole+1, description);
}

void CardDVB::setOnOff(bool onOff) {
    this->onOff=onOff ;
    QString imgPath=onOff?"images/On.png":"images/Off.png";
    this->setData(Qt::DecorationRole, imgPath);
}
