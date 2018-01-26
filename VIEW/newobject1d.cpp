#include "newobject1d.h"

NewObject1D::NewObject1D(BusinessLogic *l, QDialog *parent) : QDialog(parent)
{
    log = l;

    //per settare come finestra object 1D create
    this->setWindowTitle("Add new Object1D");
    QDialog::reject();
    this->setModal(true);
    this->resize(500,300);

    //si costruisce struttura a griglia
    struttura = new QGridLayout(this);
    // box con scritta che contiene tutti gli altri box per la creazione
    newLineBox = new QGroupBox(tr("Create new Object1D"));
    setWindowTitle(tr("Create new Object1D"));
    // box dove si setta lunghezza e risoluzione
    gridBox = new QGridLayout();

    //label
    QLabel* lung = new QLabel(tr("Length:"));
    length = new QLineEdit();
    QLabel* r = new QLabel(tr("Resolution:"));
    risoluzione = new QLineEdit();

    //posizionamento in griglia dei widget
    gridBox->addWidget(lung, 0, 0);
    gridBox->addWidget(length, 0, 1);
    gridBox->addWidget(r, 1, 0);
    gridBox->addWidget(risoluzione, 1, 1);

    // zona misure
    boxMisura = new QGroupBox();
    gridMisura = new QGridLayout(this);

    //bottoni settaggio misure
    QRadioButton* px = new QRadioButton(tr("px"));
    QRadioButton* cm = new QRadioButton(tr("cm"));
    QRadioButton* inch = new QRadioButton(tr("inch"));

    //This property holds whether the button is checked. Only checkable buttons can be checked. By default, the button is unchecked.
    px->setChecked(true);

    //px -> 0
    misura = 0;

    //posizionamento in griglia dei widget
    gridMisura->addWidget(px, 0, 0);
    gridMisura->addWidget(cm, 1, 0);
    gridMisura->addWidget(inch, 2, 0);

    boxMisura->setLayout(gridMisura);
    gridBox->addWidget(boxMisura,0,2);

    //bottone creazione
    create = new QPushButton(tr("Create"));

    //aggiungo al layout generale anche il bottone
    gridBox->addWidget(create, 2, 1);

    //sistemo il layout mettendo tutto insieme
    newLineBox->setLayout(gridBox);
    struttura->addWidget(newLineBox, 0, 0);

    //connect
    connect(create, SIGNAL(clicked()), this, SLOT(saveObject1D()));
    connect(px, SIGNAL(clicked()),this,SLOT(setPx()));
    connect(cm, SIGNAL(clicked()),this,SLOT(setCm()));
    connect(inch, SIGNAL(clicked()),this,SLOT(setInch()));

}

void NewObject1D::saveObject1D()
{
    //messaaggi errori o warning
    QMessageBox errorMsg;
    errorMsg.setWindowTitle(tr("Error!"));
    bool error = false;
    QMessageBox warningMsg;
    warningMsg.setWindowTitle(tr("Attention!"));
    bool warning = false;

    //controlli su lunghezze
    QString s = QString(length->text());
    if(s.trimmed().isEmpty()){
        errorMsg.setInformativeText(tr("Insert string not empy pls!"));
        error = true;
    }
    double lungD = (length->text().toDouble());
    if(lungD == 0){
         warningMsg.setText(tr("value = 0 or value not valid"));
         warningMsg.setInformativeText(tr("set new Object1D to 1px"));
         warning = true;
    }
    //unità di misura (correlato lunghezza obj1D) check
    int l;
    if(misura==1) l = static_cast<int>(lungD*risoluzione->text().toInt()*2.54); //risoluzione->text().toInt() == risoluzione space (dpi)
    else if (misura==2) l = static_cast<int>(lungD*risoluzione->text().toDouble());
    else l = (length->text()).toInt();
    //check punti per pollice
    int ris = risoluzione->text().toInt();
    if(ris==0){
        errorMsg.setText(tr("dpi not valid, insert new dots per inch"));
        error = true;
    }

    //set all
    if(error) errorMsg.exec();
    else {
        if(l == 0) l = 1; // lunghezza di un oggetto a 1D non può essere 0, minimo 1 che coincide con un punto
        if(warning) warningMsg.exec();
        log->newObj1D(l,ris); //effettiva chiamata di creazione nuovo Objec1D


        //log adesso contiene almeno un oggetto 1D nella lista

        emit Object1DAdded();
        length->setText("");
        risoluzione->setText("");
        QDialog::close();
    }

}

void NewObject1D::setPx()
{
    misura=0;
    update();
    repaint();
}

void NewObject1D::setCm()
{
    misura=1;
    update();
    repaint();
}

void NewObject1D::setInch()
{
    misura=2;
    update();
    repaint();
}

