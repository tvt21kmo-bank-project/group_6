QT       += core gui
QT +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apusivu.cpp \
    main.cpp \
    mainwindow.cpp \
    muusumma.cpp \
    muusummanosto.cpp \
    nostarahaa.cpp \
    paasivu.cpp \
    pano.cpp \
    timer2.cpp \
    toimintosivu.cpp \
    tyyppi.cpp \
    tilitapahtumat.cpp

HEADERS += \
    apusivu.h \
    mainwindow.h \
    muusumma.h \
    muusummanosto.h \
    nostarahaa.h \
    paasivu.h \
    pano.h \
    timer2.h \
    toimintosivu.h \
    tyyppi.h \
    tilitapahtumat.h

FORMS += \
    mainwindow.ui \
    muusumma.ui \
    muusummanosto.ui \
    nostarahaa.ui \
    paasivu.ui \
    pano.ui \
    toimintosivu.ui \
    tyyppi.ui \
    tilitapahtumat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
