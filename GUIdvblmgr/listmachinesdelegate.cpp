#include "listmachinesdelegate.h"

ListMachinesDelegate::ListMachinesDelegate(QObject *parent) :
    QAbstractItemDelegate(parent)
{
}

void ListMachinesDelegate::paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const{
    QRect r = option.rect;

    QPen transparentPen(Qt::transparent, 0, Qt::SolidLine); //just to avoid drawing the lines around the rectangles
    painter->setPen(transparentPen);

    if(option.state & QStyle::State_Selected){
        QLinearGradient gradientSelected(r.left(),r.top(),r.left(),r.height()+r.top());
        gradientSelected.setColorAt(0.0, QColor::fromRgb(230,230,240));
        gradientSelected.setColorAt(1.0, QColor::fromRgb(140,140,160));
        painter->setBrush(gradientSelected);
        painter->drawRect(r);
    }
    else {
        painter->setBrush( (index.row() % 2) ? Qt::white : QColor(245,245,250) );
        painter->drawRect(r);
    }

    QPen linePen(QColor::fromRgb(140,140,160), 1.5, Qt::SolidLine);
    painter->setPen(linePen);
    QPoint left = QPoint(r.bottomLeft().rx() + 10, r.bottomLeft().ry()) ;
    QPoint right = QPoint(r.bottomRight().rx() - 10, r.bottomRight().ry()) ;
    painter->drawLine(left,right);

    QPen fontPen(QColor::fromRgb(51,51,51), 1, Qt::SolidLine);
    painter->setPen(fontPen);

    //get Machine Name, IP adress and the right image whether the machine is On or Off
    QIcon imgOnOff = QIcon(index.data(Qt::DecorationRole).toString());
    QString nameMachine = index.data(Qt::DisplayRole).toString();
    QString ipAddress = index.data(Qt::UserRole + 1).toString();

    int imageSpace = 10;
    if (!imgOnOff.isNull()) {
        r = option.rect.adjusted(5, 30, -10, -30);
        imgOnOff.paint(painter, r, Qt::AlignVCenter|Qt::AlignRight);
        imageSpace = 55;
    }

    //Machine Name
    r = option.rect.adjusted(10, 0, -imageSpace, -30);
    painter->setFont( QFont( "Calibri", 15, QFont::Normal ) );
    painter->drawText(r.left(), r.top(), r.width(), r.height(), Qt::AlignTop|Qt::AlignLeft, nameMachine, &r);

    //IP adress
    r = option.rect.adjusted(30, 30, -imageSpace, -30);
    painter->setFont( QFont( "Calibri",11, QFont::Light, true ) );
    painter->drawText(r.left(), r.top(), r.width(), r.height(), Qt::AlignLeft, ipAddress, &r);
}

QSize ListMachinesDelegate::sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const{
    return QSize(300, 90);
}
