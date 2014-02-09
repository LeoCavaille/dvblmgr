#ifndef LISTMACHINES_H
#define LISTMACHINES_H

#include <QListWidget>
#include <QList>
#include "machine.h"
#include "listmachinesdelegate.h"


class ListMachines : public QListWidget
{
    Q_OBJECT

public:
    explicit ListMachines(QWidget *parent = 0);
    Machine* getMachineAtPosition(int position) ;

};


#endif // LISTMACHINES_H
