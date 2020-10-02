#ifndef DLG_INVOICE_ALL_H
#define DLG_INVOICE_ALL_H

#include <QDialog>

namespace Ui {
class DlgInvoiceAll;
}

class DlgInvoiceAll : public QDialog
{
    Q_OBJECT

public:
    explicit DlgInvoiceAll(QWidget *parent = 0);
    ~DlgInvoiceAll();

private:
    Ui::DlgInvoiceAll *ui;
};

#endif // DLG_INVOICE_ALL_H
