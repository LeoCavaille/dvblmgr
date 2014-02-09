#include "button.h"

Button::Button(QWidget *parent, QString buttonName) :
    QPushButton(parent)
{
    setIcon(QIcon("images/"+buttonName+".png"));
    setFixedSize(30,30);
    show();
}
