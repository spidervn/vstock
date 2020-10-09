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

private slots:
    void on_pushButton_clicked();

    void on_DlgInvoiceAll_accepted();

    void on_pushButton_2_clicked();

private:
    Ui::DlgInvoiceAll *ui;
};

#endif // DLG_INVOICE_ALL_H
