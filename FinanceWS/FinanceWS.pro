#-------------------------------------------------
#
# Project created by QtCreator 2020-10-01T13:40:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FinanceWS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    UI/dlg_invoice_all.cpp \
    Test/testmodelview.cpp \
    Test/stringlistmodel.cpp \
    Test/spinboxdelegate.cpp

HEADERS += \
        mainwindow.h \
    UI/dlg_invoice_all.h \
    Test/testmodelview.h \
    Test/stringlistmodel.h \
    Test/spinboxdelegate.h

FORMS += \
        mainwindow.ui \
    UI/categorydlg.ui \
    UI/dlg_invoice_all.ui \
    UI/categoryall_dlg.ui \
    UI/categoryadd_dlg.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../setup/database/postgres/postgresql-12.4/BINDIR/lib/release/ -lpq
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../setup/database/postgres/postgresql-12.4/BINDIR/lib/debug/ -lpq
else:unix: LIBS += -L$$PWD/../../../../setup/database/postgres/postgresql-12.4/BINDIR/lib/ -lpq

INCLUDEPATH += $$PWD/../../../../setup/database/postgres/postgresql-12.4/BINDIR/include
DEPENDPATH += $$PWD/../../../../setup/database/postgres/postgresql-12.4/BINDIR/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../setup/database/postgres/postgresql-12.4/BINDIR/lib/release/libpq.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../setup/database/postgres/postgresql-12.4/BINDIR/lib/debug/libpq.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../setup/database/postgres/postgresql-12.4/BINDIR/lib/release/pq.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../setup/database/postgres/postgresql-12.4/BINDIR/lib/debug/pq.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../setup/database/postgres/postgresql-12.4/BINDIR/lib/libpq.a
