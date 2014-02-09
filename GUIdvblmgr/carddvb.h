#ifndef CARDDVB_H
#define CARDDVB_H

#include <QListWidgetItem>

class CardDVB : public QListWidgetItem
{
    //Q_OBJECT
public:
    explicit CardDVB(QListWidget *parent = 0, QString cardID= "");
    QString getCardID() ;
    QString getDescription() ;
    bool isOnOff() ;
    void setCardID(QString cardID) ;
    void setDescription(QString description) ;
    void setOnOff(bool onOff) ;

private:
    QString cardID ;
    QString description ;
    bool onOff ;

};

#endif // CARDDVB_H
