#ifndef LISTCARDSDELEGATE_H
#define LISTCARDSDELEGATE_H

#include <QAbstractItemDelegate>
#include <QPainter>

class ListCardsDelegate : public QAbstractItemDelegate
{
    Q_OBJECT
public:
    explicit ListCardsDelegate(QObject *parent = 0);
    void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
    QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const;

};

#endif // LISTCARDSDELEGATE_H
