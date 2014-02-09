#include "listcards.h"

ListCards::ListCards(QWidget *parent) :
    QListWidget(parent)
{
    show();
    setMinimumWidth(320);
    setMaximumWidth(400);
    setItemDelegate(new ListCardsDelegate(this)); //for the style of the list
}

void ListCards::hideAllCards(){
    for (int i=0;i<count(); i++){
        setItemHidden(item(i),true) ;
    }
}
