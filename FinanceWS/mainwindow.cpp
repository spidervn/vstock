#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UI/dlg_invoice_all.h"

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
    dlg.showFullScreen();
}
