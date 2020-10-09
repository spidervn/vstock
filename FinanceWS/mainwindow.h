#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonMain_clicked();

    void on_actionH_a_n_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
