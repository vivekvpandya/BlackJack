#-------------------------------------------------
#
# Project created by QtCreator 2015-10-22T11:45:47
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BlackJack
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    card.cpp \
    carddrawing.cpp \
    deck.cpp \
    player.cpp \
    connectionwindow.cpp \
    networkoperationmanager.cpp \
    table.cpp

HEADERS  += mainwindow.h \
    card.h \
    carddrawing.h \
    deck.h \
    player.h \
    connectionwindow.h \
    networkoperationmanager.h \
    table.h

FORMS    += mainwindow.ui \
    carddrawing.ui \
    connectionwindow.ui

RESOURCES += \
    resources.qrc
