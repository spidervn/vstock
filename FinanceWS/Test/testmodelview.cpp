#include "testmodelview.h"
#include <QFileSystemModel>
#include <QListView>
#include <QObject>
#include <QSplitter>
#include <QTreeView>

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
