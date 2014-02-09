#include "listmachines.h"
#include <QDesktopWidget>

ListMachines::ListMachines(QWidget *parent) :
    QListWidget(parent)
{
    show();
    setMinimumWidth(320);
    setMaximumWidth(400);
    setItemDelegate(new ListMachinesDelegate(this)); // for the style of the list
}

Machine* ListMachines::getMachineAtPosition(int position) {
    return (Machine *) this->item(position) ;
}
