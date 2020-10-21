#include "testmodelview.h"
#include <QFileSystemModel>
#include <QListView>
#include <QObject>
#include <QPushButton>
#include <QSplitter>
#include <QTableView>
#include <QTreeView>
#include <QStandardItemModel>
#include <QStringListModel>
#include "spinboxdelegate.h"
#include "stringlistmodel.h"

TestModelView::TestModelView()
{
}

int TestModelView::runTest(QApplication* app)
{
    QSplitter* splitter = new QSplitter;
    QFileSystemModel* model = new QFileSystemModel();
    model->setRootPath("/home/ducvd/code/"); // QDir::currentPath()

    QObject::connect(model, &QFileSystemModel::directoryLoaded, [model](const QString& directory) {
        QModelIndex parentIndex = model->index(directory);
        int num_rows = model->rowCount(parentIndex);
    });

    QTreeView* tree = new QTreeView(splitter);
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));

    QListView* list = new QListView(splitter);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::currentPath()));

    splitter->setWindowTitle("Two views onto the same file system model");
    splitter->show();

    return app->exec();
}

int TestModelView::runTestView(QApplication* app)
{
    QStringList numbers;
    QSplitter* splitter = new QSplitter;

    numbers << "One" << "Two" << "Three" << "Four" << "Five";
    QAbstractItemModel *model = new StringListModel(numbers);

    QListView *view = new QListView(splitter);
    QTableView *tview = new QTableView(splitter);
    QTableView *tview2 = new QTableView(splitter);
    QTableView *tview3 = new QTableView(splitter);
    QPushButton* btn = new QPushButton("Remove First", splitter);

    QObject::connect(
                btn,
                &QPushButton::clicked,
                [btn, model](bool checked) {
                    printf("Remove a row");
                    model->removeRow(0);
                });

    // QObject::connect(btn, QPushButton::)
    view->setModel(model);
    tview->setModel(model);
    tview2->setModel(model);
    tview2->setSelectionModel(tview->selectionModel());
    view->setSelectionModel(tview->selectionModel());

    QModelIndex topLeft;
    QModelIndex bottRight;
    topLeft = model->index(0, 0, QModelIndex());
    bottRight =model->index(3, 0, QModelIndex());

    QItemSelection selection(topLeft, bottRight);
    tview->selectionModel()->select(selection, QItemSelectionModel::Select);
    tview->setDragEnabled(true);

    //=======TView3===============
    QStandardItemModel sim(4,2);
    SpinBoxDelegate spbdlgt;

    tview3->setModel(&sim);
    tview3->setItemDelegate(&spbdlgt);

    // What is selection model?
    splitter->setWindowTitle("Splitter");
    splitter->show();
    return app->exec();
}

