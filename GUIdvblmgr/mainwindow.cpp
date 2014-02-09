#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Main Window properties
    ui->setupUi(this);
    setWindowTitle("DVBlastManager") ;
    resize(900, 750) ;
    showMaximized(); //The MainWindow is opened by default in Full Screen size

    loadMenu();
    loadWidgets();
    loadData();

    //signals and their connection to slots
    machineSelectionChanged();

    connect(quit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(refresh, SIGNAL(triggered()), this, SLOT(machineSelectionChanged()));
    connect(listMachines, SIGNAL(itemSelectionChanged()), this, SLOT(machineSelectionChanged()));
    connect(listCards, SIGNAL(itemSelectionChanged()), this, SLOT(cardSelectionChanged()));
}

void MainWindow::loadMenu(){
    quit = new QAction("&Quit", this);
    quit->setShortcut(tr("Ctrl+Q"));
    refresh = new QAction("&Refresh", this);

    file = menuBar()->addMenu("&File");
    file->addAction(refresh);
    file->addSeparator();
    file->addAction(quit);
}

void MainWindow::loadWidgets(){
    //Creation of a layout that will allow to diplay all the information (lists and buttons and so on) so that they will automatically be resized when the mainwindow will be resized
    QWidget* widget = new QWidget(this);
    setCentralWidget(widget);
    mainLayout = new QGridLayout() ;
    widget->setLayout(mainLayout);

    listMachines = new ListMachines(this) ;
    listCards = new ListCards(this) ;

    newMachine = new Button (this, "New") ;
    deleteMachine = new Button (this, "Delete") ;
    editMachine = new Button (this, "Edit") ;

    newCard = new Button (this, "New") ;
    deleteCard = new Button (this, "Delete") ;
    editCard = new Button (this, "Edit") ;

    layoutMachines = new QGridLayout();
    layoutMachines->setAlignment(Qt::AlignLeft) ;
    layoutMachines->addWidget(newMachine, 0, 0);
    layoutMachines->addWidget(deleteMachine, 0, 1);
    layoutMachines->addWidget(editMachine, 0, 2);
    layoutMachines->addWidget(listMachines, 1, 0, 1, 6) ;

    layoutCards = new QGridLayout();
    layoutCards->setAlignment(Qt::AlignLeft) ;
    layoutCards->addWidget(newCard, 0, 0);
    layoutCards->addWidget(deleteCard, 0, 1);
    layoutCards->addWidget(editCard, 0, 2);
    layoutCards->addWidget(listCards, 1, 0, 1, 6) ;

    machineInformation = new QGroupBox(this) ;
    machineInformation->show();
    machineInformation->setMinimumSize(350, 300);
    machineInformation->setStyleSheet("QGroupBox{border: 1px solid gray; border-radius: 5px; margin-top: 0.5em;} QGroupBox::title {subcontrol-origin: margin; left: 20px; padding: 0 3px 0 3px;}");

    cardInformation = new QGroupBox(this) ;
    cardInformation->show();
    cardInformation->setMinimumSize(200, 200);
    cardInformation->setStyleSheet("QGroupBox{border: 1px solid gray; border-radius: 5px; margin-top: 0.5em;} QGroupBox::title {subcontrol-origin: margin; left: 20px; padding: 0 3px 0 3px;}");

    //Layout organisation
    mainLayout->addLayout(layoutMachines, 0, 0, 3, 1);
    mainLayout->addWidget(machineInformation, 0, 1, 2, 3);
    mainLayout->addLayout(layoutCards, 2, 1, 1, 1);
    mainLayout->addWidget(cardInformation, 2, 2, 1, 2);
}

void MainWindow::loadData(){
    //this method is used to load the data (cards and machines). Here is some machines and cards loaded as an example
    //this method will be used to read a configuration file that lists all the machines and their cards

    //creation of a list of 25 machines
    for (int i=1; i<25; i++){
        listMachines->addItem(new Machine(listMachines, "Machine "+(QString::number(i)))) ;
    }

    //adding some cards to some of the machines
    listMachines->getMachineAtPosition(0)->addCard(new CardDVB(listCards, "CarteDVB 1")) ;
    listMachines->getMachineAtPosition(0)->addCard(new CardDVB(listCards, "CarteDVB 2")) ;
    listMachines->getMachineAtPosition(1)->addCard(new CardDVB(listCards, "CarteDVB 3")) ;
    listMachines->getMachineAtPosition(2)->addCard(new CardDVB(listCards, "CarteDVB 4")) ;
    listMachines->getMachineAtPosition(2)->addCard(new CardDVB(listCards, "CarteDVB 5")) ;
    listMachines->getMachineAtPosition(4)->addCard(new CardDVB(listCards, "CarteDVB 6")) ;
    listMachines->getMachineAtPosition(4)->addCard(new CardDVB(listCards, "CarteDVB 7")) ;
    listMachines->getMachineAtPosition(4)->addCard(new CardDVB(listCards, "CarteDVB 8")) ;

    //example of how to change the Ip addresses or descriptions or if they're on or off for machines and cards
    listMachines->getMachineAtPosition(1)->setIpAddress("192.167.0.1");
    listMachines->getMachineAtPosition(1)->setOnOff(false);
    listMachines->getMachineAtPosition(4)->getListOfCardsDVB()->at(0)->setOnOff(false);
    listMachines->getMachineAtPosition(4)->getListOfCardsDVB()->at(0)->setDescription("TF1 / France 2/ France 3");

    //initialisation of the list by selecting the first item
    listMachines->setItemSelected(listMachines->item(0), true);
    listMachines->setCurrentItem(listMachines->item(0));
}

void MainWindow::machineSelectionChanged(){
    //event (slot in Qt) generated when the selected machine in the list has changed
    listCards->hideAllCards() ;
    listCards->setCurrentItem(NULL);
    Machine* selectedMachine = (Machine*) listMachines->currentItem() ;
    machineInformation->setTitle(selectedMachine->text());//the selected machine has changed, thus its information should be uploaded too
    //the list of the cards linked to the selected machine has to be updated too
    if (selectedMachine->getListOfCardsDVB() != NULL){
        for(int i=0;i<selectedMachine->getListOfCardsDVB()->size();i++){
            CardDVB* cardToBeDisplayed = selectedMachine->getListOfCardsDVB()->at(i) ;
            listCards->setItemHidden(cardToBeDisplayed, false);
        }
    }
    cardSelectionChanged();//the selected card has changed thus its information has to be updated too
}

void MainWindow::cardSelectionChanged(){
    CardDVB* selectedCard = (CardDVB*) listCards->currentItem() ;
    if (selectedCard!=NULL){
        cardInformation->setTitle(selectedCard->text());
    }
    else{
        cardInformation->setTitle("");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete listMachines ;
    delete listCards ;
    delete machineInformation ;
    delete cardInformation ;

    delete quit ;
    delete refresh ;
    delete file;

    delete newMachine ;
    delete deleteMachine ;
    delete editMachine ;
    delete newCard ;
    delete deleteCard ;
    delete editCard ;

    delete mainLayout ;
    delete layoutMachines ;
    delete layoutCards ;
}
