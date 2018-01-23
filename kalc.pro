#-------------------------------------------------
#
# Project created by QtCreator 2017-12-13T16:33:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kalc
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
    MODEL/rgbhex.cpp \
    MODEL/space.cpp \
    MODEL/object_1d.cpp \
    MODEL/object_2d.cpp \
    MODEL/object_3d.cpp \
    MODEL/businesslogic.cpp \
    MODEL/status.cpp \
    MODEL/object.cpp \
    VIEW/colorrange.cpp \
    VIEW/colorzone.cpp \
    VIEW/createcolor.cpp \
    VIEW/newobject1d.cpp \
    VIEW/newobject2d.cpp \
    VIEW/newobject3d.cpp \
    VIEW/operatori.cpp \
    VIEW/select.cpp \
    VIEW/selectdetails.cpp \
    VIEW/table.cpp \
    VIEW/calculate.cpp

HEADERS += \
        mainwindow.h \
    MODEL/rgbhex.h \
    MODEL/space.h \
    MODEL/object_1d.h \
    MODEL/object_2d.h \
    MODEL/object_3d.h \
    MODEL/exceptions.h \
    MODEL/businesslogic.h \
    MODEL/status.h \
    MODEL/object.h \
    VIEW/colorrange.h \
    VIEW/colorzone.h \
    VIEW/createcolor.h \
    VIEW/newobject1d.h \
    VIEW/newobject2d.h \
    VIEW/newobject3d.h \
    VIEW/operatori.h \
    VIEW/select.h \
    VIEW/selectdetails.h \
    VIEW/table.h \
    VIEW/calculate.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    icons.qrc
