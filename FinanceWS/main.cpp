#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QObject>
#include <QString>
#include <QtCore/QString>
#include <QMessageBox>
#include <libpq-fe.h>
#include <stdio.h>
#include <stdlib.h>
#include "Test/testmodelview.h"

int testPG()
{
    PGconn* conn;
    PGresult* res;
    int nFields;
    int i, j;

    const char* connInfo = "dbname=postgres";

    conn = PQconnectdb(connInfo);

    if (PQstatus(conn) == CONNECTION_OK)
    {
        printf("Connection to database failed: %s\r\n");
        PQfinish(conn);
        return -1;
    }

    res = PQexec(conn, "SELECT pg_catalog.set_config('search_path', '', false)");
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        fprintf(stderr, "SET failed: %s", PQerrorMessage(conn));
        PQclear(res);
        PQfinish(conn);
        return -1;
    }
    PQclear(res);

    return 0;
}

int SLOTNewFile()
{
    QMessageBox* pbox = new QMessageBox();
    pbox->setText("OK");
    pbox->exec();
    return 0;
}

int SLOTOpenFile()
{
    return 0;
}

int testLayout(QApplication* app)
{
    QWidget* window = new QWidget;
    QPushButton* button1 = new QPushButton("One");
    QPushButton* button2 = new QPushButton("Two");
    QPushButton* button3 = new QPushButton("Three");
    QPushButton* button4 = new QPushButton("Four");
    QPushButton* button5 = new QPushButton("Five");

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    layout->addWidget(button5);

    window->setLayout(layout);
    window->show();

    return app->exec();
}

int testMainWindow(QApplication* app)
{

    QMainWindow* qmain = new QMainWindow();
    qmain->resize(600, 400);

    QAction* newAct;
    QAction* openAct;

    newAct = new QAction(QObject::tr("&New"), qmain->window()); // this = MainWindow
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(QObject::QObject::tr("Create a new file"));

    openAct = new QAction(QObject::tr("&Open"), qmain->window());
    openAct->setShortcut(QKeySequence::Open);
    openAct->setStatusTip(QObject::tr("Open an existing file"));

    QObject::connect(newAct, &QAction::triggered, qmain->window(), SLOTNewFile);
    QObject::connect(openAct, &QAction::triggered, qmain->window(), SLOTOpenFile);

    QMenu* fileMenu = qmain->menuBar()->addMenu(QObject::tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();

    QToolBar* fileToolBar = qmain->addToolBar(QObject::tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea | Qt::LeftToolBarArea);

    QDockWidget* contentsWindow = new QDockWidget(QObject::tr("Table of Contents"));
    QListWidget* headingList = new QListWidget(contentsWindow);
    contentsWindow->setWidget(headingList);

    qmain->setCentralWidget(contentsWindow);
    qmain->addToolBar(Qt::TopToolBarArea, fileToolBar);
    qmain->show();

    return app->exec();
}

int nested_layout(QApplication* app)
{
    QWidget window;
    QLabel* queryLabel = new QLabel(QApplication::translate("nestedlayout", "Query:"));
    QLineEdit* queryEdit = new QLineEdit();
    QTableView* resultView = new QTableView();

    // Setting up the Model
    QStandardItemModel model;
    model.setHorizontalHeaderLabels({
                                        QApplication::translate("nestedlayouts", "Name"),
                                        QApplication::translate("nestedlayouts", "Office")
                                    });

    const QStringList rows[] = {
        QStringList{ QStringLiteral("Verne Nilsen"), QStringLiteral("123")},
        QStringList{ QStringLiteral("Carlos Tang"), QStringLiteral("77")},
        QStringList{ QStringLiteral("Bronwyn Hawcroft"), QStringLiteral("119")},
        QStringList{ QStringLiteral("Alessandro Hanssen"), QStringLiteral("32")},
        QStringList{ QStringLiteral("Andrew John Bakken"), QStringLiteral("54 ")},
        QStringList{ QStringLiteral("Vanessa Weatherley"), QStringLiteral("85")},
        QStringList{ QStringLiteral("Rebecca Dickens"), QStringLiteral("17")},
        QStringList{ QStringLiteral("David Bradley"), QStringLiteral("42")},
        QStringList{ QStringLiteral("Knut Walters"), QStringLiteral("25")},
        QStringList{ QStringLiteral("Andrea Jones"), QStringLiteral("34")}
    };
    QList<QStandardItem*> items;
    for (const QStringList&row: rows) {
        items.clear();

        for (const QString& text: row)
        {
            items.append(new QStandardItem(text));
        }
        model.appendRow(items);
    }

    resultView->setModel(&model);
    resultView->verticalHeader()->hide();
    resultView->horizontalHeader()->setStretchLastSection(true);

    // Layout
    QHBoxLayout* queryLayout = new QHBoxLayout();
    queryLayout->addWidget(queryLabel);
    queryLayout->addWidget(queryEdit);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addLayout(queryLayout);
    mainLayout->addWidget(resultView);


    window.setLayout(mainLayout);
    window.setWindowTitle(QApplication::translate("nestedlayouts", "Nested layouts"));
    window.show();
    return app->exec();
}

int layout(QApplication* app)
{
    QWidget qwin;

    QPushButton* button = new QPushButton(QApplication::translate("childwidget", "Press me"), &qwin);
    button->move(100,100);
    button->show();

    QLabel* label = new QLabel(QApplication::translate("windowlayout", "Name"));
    QLineEdit* lineEdit = new QLineEdit();

    QHBoxLayout* layout = new QHBoxLayout();

    layout->addWidget(label);
    layout->addWidget(lineEdit);
    qwin.setLayout(layout);

    qwin.show();
    qwin.setWindowTitle("Title");

    app->exec();
    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //return testMainWindow(&a);
    // return testLayout(&a);
    // return nested_layout(&a);
    TestModelView tmv;
    tmv.runTestView(&a);

    return 0;
}
