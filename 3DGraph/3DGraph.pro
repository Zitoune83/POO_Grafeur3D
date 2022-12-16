QT       += core gui datavisualization

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    classes/Addition.cpp \
    classes/Constante.cpp \
    classes/Division.cpp \
    classes/Expression.cpp \
    classes/Multiplication.cpp \
    classes/OperateurBinaire.cpp \
    classes/Soustraction.cpp \
    main.cpp \
    model.cpp \
    view.cpp

HEADERS += \
    classes/Addition.h \
    classes/Constante.h \
    classes/Division.h \
    classes/Expression.h \
    classes/Multiplication.h \
    classes/OperateurBinaire.h \
    classes/Soustraction.h \
    model.h \
    view.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
