#ifndef LISTMACHINESDELEGATE_H
#define LISTMACHINESDELEGATE_H

#include <QAbstractItemDelegate>
#include <QPainter>

class ListMachinesDelegate : public QAbstractItemDelegate
{
    Q_OBJECT
public:
    explicit ListMachinesDelegate(QObject *parent = 0);
    void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
    QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const;

};

#endif // LISTMACHINESDELEGATE_H
