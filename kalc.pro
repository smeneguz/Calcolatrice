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
    VIEW/boh.cpp \
    MODEL/rgbhex.cpp \
    MODEL/space.cpp \
    MODEL/object_1d.cpp \
    MODEL/object_2d.cpp \
    MODEL/object_3d.cpp \
    MODEL/businesslogic.cpp \
    MODEL/status.cpp

HEADERS += \
        mainwindow.h \
    VIEW/boh.h \
    MODEL/rgbhex.h \
    MODEL/space.h \
    MODEL/object_1d.h \
    MODEL/object_2d.h \
    MODEL/object_3d.h \
    MODEL/exceptions.h \
    MODEL/businesslogic.h \
    MODEL/status.h

FORMS += \
        mainwindow.ui
