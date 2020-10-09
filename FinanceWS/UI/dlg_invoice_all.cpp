#include "dlg_invoice_all.h"
#include "ui_dlg_invoice_all.h"

DlgInvoiceAll::DlgInvoiceAll(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgInvoiceAll)
{
    ui->setupUi(this);
}

DlgInvoiceAll::~DlgInvoiceAll()
{
    delete ui;
}


void DlgInvoiceAll::on_pushButton_clicked()
{

}

void DlgInvoiceAll::on_DlgInvoiceAll_accepted()
{
    printf("Accepted");
}
