#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QList>
#include <QString>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>

#include "listmachines.h"
#include "listcards.h"
#include "button.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadData();
    void loadMenu();
    void loadWidgets();

public slots :
    void machineSelectionChanged();
    void cardSelectionChanged();

private:
    Ui::MainWindow *ui;
    ListMachines *listMachines ; //the list which contains the servers with a DVB card
    ListCards *listCards ; //the list of the DVB cards (only the ones of the currently selected machine will be displayed)
    QGroupBox *machineInformation ; //Information about the currently selected machine
    QGroupBox *cardInformation ; //Information about the currently selected card

    //attributes for the menu bar
    QAction *quit ;
    QAction *refresh ;
    QMenu *file;

    //pushbuttons
    Button *newMachine ;
    Button *deleteMachine ;
    Button *editMachine ;
    Button *newCard ;
    Button *deleteCard ;
    Button *editCard ;

    //all the different layouts used to achieve the layout of the main window
    QGridLayout *mainLayout ;
    QGridLayout *layoutMachines ;
    QGridLayout *layoutCards ;


};

#endif // MAINWINDOW_H
