#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QApplication>
#include <QCloseEvent>

#include <QMenu>
#include <QToolBar>
#include <QFile>

#include <QMainWindow>

#include "./VIEW/toolbar.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    Ui::MainWindow *ui;

    /* Sezione principale */
    Toolbar* section;



   // FormContinua* form;








private slots:
   //void store();
   //void chiudi();
   //void mostraTutto();
   //void nascondi();
   //void aggiungiDato();
   //void aggiungiNuovo();


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

};

#endif // MAINWINDOW_H
