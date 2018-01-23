#include "calculate.h"

QString Calculate::stringResult(Object *o) const
{
    QString l = QString(tr(""));
    QString h = QString(tr(""));
    QString d = QString(tr(""));
    QString dpis = QString(tr(""));
    QString mis = QString(tr("")); //default pixel
    Status s = log->getStatus(*o);
    QString c = QString::fromStdString(s.color);
    if((s.l) > 0) { // c'è una lunghezza -> minimo oggetto1D
        l = QString::number(s.l);
        mis = QString(tr("pixel"));
    }
    if((s.h) > 0) h = "x" + QString::number(s.h); //minimo un oggetto an 2D
    if((s.d) > 0) d = "x" + QString::number(s.d); //oggetto a 3D
    if((s.dpi) > 0) dpis = "@" + QString::number(s.dpi) + "dpi";
    QString res = l + h + d + mis + dpis + c;
    return res;
}

Calculate::Calculate(BusinessLogic *l, QWidget *parent) : QWidget(parent), log(l)
{
    //first operand
    QLabel* l1o = new QLabel(tr("first Operand"));
    firsto = new QLineEdit();
    add1o = new QPushButton(tr("add here"));

    //operator
    op = new Operatori();

    //second operand
    QLabel* l2o = new QLabel(tr("second Operand"));
    secondo = new QLineEdit();
    add2o = new QPushButton(tr("add here"));

    //struct layout fisrt part
    struttura = new QGridLayout(this);
    struttura->addWidget(l1o, 0, 0);
    struttura->addWidget(firsto, 1, 0);
    struttura->addWidget(add1o, 2, 0);
    struttura->addWidget(op, 0, 1, 3, 1);
    struttura->addWidget(l2o, 0, 2);
    struttura->addWidget(secondo, 1, 2);
    struttura->addWidget(add2o, 2, 2);

    // uguale
    uguale = new QPushButton(tr("="), this);

    //risultato
    QLabel* rl = new QLabel(tr("result"));
    risultato = new QLineEdit();
    save = new QPushButton(tr("Save"));

    //clear
    QPushButton* clearP = new QPushButton(tr("Clear"), this);

    //struct second part
    struttura->addWidget(uguale, 1, 3);
    struttura->addWidget(clearP, 2, 3);
    struttura->addWidget(rl, 0, 4);
    struttura->addWidget(risultato, 1, 4);
    struttura->addWidget(save, 2, 4);

    //Connect Button
    connect(add1o, SIGNAL(clicked()), this, SLOT(addOp1()));
    connect(add2o, SIGNAL(clicked()), this, SLOT(addOp2()));
    connect(op, SIGNAL(operatorChanged()), this, SLOT(setOperator()));
    connect(uguale, SIGNAL(clicked()), this, SLOT(execute()));
    connect(clearP, SIGNAL(clicked()), this, SLOT(clear()));
    connect(save, SIGNAL(clicked()), this, SLOT(saveResult()));



}

void Calculate::setOperator()
{
    log->setOperator(op->getSelectedOperator());
}

void Calculate::addOp1()
{
    Object* sel = log->getSelezione();
    log->setOp1(sel); //setto l'operando selezionato come primo
    if(sel){
        Object* o1 = log->getOp1();
        QString aux = stringResult(o1); // mi ritorna una stringa rappresentante il valore dell'object passato
        firsto->setText(aux);
    }
}

void Calculate::addOp2()
{
    Object* sel = log->getSelezione();
    log->setOp2(sel); //setto l'operando selezionato come secondo
    if(sel){
        Object* o2 = log->getOp2();
        QString aux = stringResult(o2); // mi ritorna una stringa rappresentante il valore dell'object passato
        firsto->setText(aux);
    }
}

void Calculate::execute()
{
    if((log->getOp1()) && (log->getOp2()) && (op->getSelectedOperator() >= 0)){ // se entro in questo if vuol dire che tutti i valori sono presenti (primo operando, secondo e operatore selezionato)
        QMessageBox* err = new QMessageBox();
        err->setWindowTitle(QString(tr("ERROR")));
        err->setText(QString(tr("values ​​are missing, pls add two operand and select one operator")));
        try { //blocco try poichè nella funzione esegui in businesslogic possono essere sollevate eccezioni
            log->esegui();
            Object* o = log->getRisultato();
            if(o) {
                QString aux = stringResult(o);
                risultato->setText(aux);
            }
            else {
                QMessageBox* boom = new QMessageBox();
                boom->setWindowTitle(QString(tr("ERROR")));
                boom->setInformativeText(QString(tr("impossible to calculate the result")));
                boom->exec();
                clear();
            }

           }
        //Catch riguardanti oggetti 1D
        catch(Ecc_Object1D_somma_ObjectDiverso){
            err->setWindowTitle(QString(tr("exception")));
            err->setInformativeText(QString(tr("Object1D can not be added to other types ")));
            err->exec();
        }
        catch(Ecc_Object1D_sottrazione_ObjectDiverso){
            err->setWindowTitle(QString(tr("exception")));
            err->setInformativeText(QString(tr("Object1D can not be subtracted to other types ")));
            err->exec();
        }
        catch(Ecc_Object1D_moltiplicazione_ObjectDiverso){
            err->setWindowTitle(QString(tr("exception")));
            err->setInformativeText(QString(tr("Object1D can not be multiplied to other types ")));
            err->exec();
        }
        catch(Ecc_Object1D_divisione_Object1D){
            err->setWindowTitle(QString(tr("exception")));
            err->setInformativeText(QString(tr("Object1D can not be divided to other types ")));
            err->exec();
        }

        //Catch riguardanti oggetti 2D
        catch(Ecc_Object2D_somma_ObjectDiverso){
            err->setWindowTitle(QString(tr("exception")));
            err->setInformativeText(QString(tr("Object2D can not be added to other types ")));
            err->exec();
        }
        catch(Ecc_Object2D_sottrazione_ObjectDiverso){
            err->setWindowTitle(QString(tr("exception")));
            err->setInformativeText(QString(tr("Object2D can not be subtracted to other types ")));
            err->exec();
        }
        catch(Ecc_Object2D_moltiplicazione_ObjectDiverso){
            err->setWindowTitle(QString(tr("exception")));
            err->setInformativeText(QString(tr("Object2D can not be multiplied to other types (except with Object1D) ")));
            err->exec();
        }
        catch(Ecc_Object2D_divisione_ObjectDiverso){
            err->setWindowTitle(QString(tr("exception")));
            err->setInformativeText(QString(tr("Object2D can not be divided to other types (except with Object1D)")));
            err->exec();
        }

        //Catch riguardanti oggetti 3D
        catch(Ecc_Object3D_somma_ObjectDiverso){
            err->setWindowTitle(QString(tr("exception")));
            err->setInformativeText(QString(tr("Object3D can not be added to other types ")));
            err->exec();
        }
        catch(Ecc_Object3D_sottrazione_ObjectDiverso){
            err->setWindowTitle(QString(tr("exception")));
            err->setInformativeText(QString(tr("Object3D can not be subtracted to other types ")));
            err->exec();
        }
        catch(Ecc_Object3D_moltiplicazione_ObjectDiverso){ //caso che in questa gerarchia non capiterà mai, ma se venisse estesa potrebbe comparire
            err->setWindowTitle(QString(tr("exception")));
            err->setInformativeText(QString(tr("Object3D can not be multiplied to other types (except with Object1D and Object2D) ")));
            err->exec();
        }
        catch(Ecc_Object3D_divisione_ObjectDiverso){//caso che in questa gerarchia non capiterà mai, ma se venisse estesa potrebbe comparire
            err->setWindowTitle(QString(tr("exception")));
            err->setInformativeText(QString(tr("Object3D can not be divided to other types (except with Object1D and Object2D)")));
            err->exec();
        }

        //Catch riguardanti RGBHex
        catch(Ecc_RGBHex_moltiplicazione_Object){
            err->setWindowTitle(QString(tr("exception")));
            err->setInformativeText(QString(tr("RGBHex Color can not be multiplied to other types ")));
            err->exec();
        }
        catch(Ecc_RGBHex_divisione_Object){
            err->setWindowTitle(QString(tr("exception")));
            err->setInformativeText(QString(tr("RGBHex Color can not be divided to other types ")));
            err->exec();
        }


        }
    //fuori dall'if, se non sono entrato vuol dire che non avevo inserito tutti i valori per poter eseguire i calcoli, quindi non faccio niente

}

void Calculate::clear()
{
    //Pulice le Qlineedit
    log->pulisci();
    firsto->setText(tr(""));
    secondo->setText(tr(""));
    risultato->setText(tr(""));
}

void Calculate::saveResult()
{
    bool ok = log->saveResult();
    this->clear();
    if(ok) emit itemAdded();

}
