#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UI/dlg_invoice_all.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonMain_clicked()
{
    DlgInvoiceAll dlg;
    dlg.exec();
}

void MainWindow::on_actionH_a_n_triggered()
{
    QMessageBox msg;
    msg.setText("OK");
    msg.show();
}
