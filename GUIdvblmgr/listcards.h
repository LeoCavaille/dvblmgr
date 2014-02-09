#ifndef LISTCARDS_H
#define LISTCARDS_H

#include <QListWidget>
#include "listcardsdelegate.h"

class ListCards : public QListWidget
{
    Q_OBJECT
public:
    explicit ListCards(QWidget *parent = 0);
    void hideAllCards();

};

#endif // LISTCARDS_H
