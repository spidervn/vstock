#ifndef TESTMODELVIEW_H
#define TESTMODELVIEW_H

#include <QApplication>
#include <QAbstractListModel>
#include <QObject>
#include <QStringList>

class TestModelView
{
public:
    TestModelView();

    int runTest(QApplication* app);

    int runTestView(QApplication* app);
};

#endif // TESTMODELVIEW_H
