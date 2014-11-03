# -------------------------------------------------
# Project created by QtCreator 2014-05-19T11:38:32
# -------------------------------------------------
TARGET = MT
TEMPLATE = app
QT += xml \
    network
SOURCES += main.cpp \
    mainwindow.cpp \
    config.cpp \
    tools.cpp \
    opt/cJSON.c \
    git.cpp \
    pushcode.cpp \
    vo/bug.cpp \
    test.cpp \
    opt/xmlhelper.cpp
HEADERS += mainwindow.h \
    config.h \
    tools.h \
    opt/cJSON.h \
    git.h \
    pushcode.h \
    vo/bug.h \
    test.h \
    opt/xmlhelper.h
FORMS += mainwindow.ui \
    config.ui \
    tools.ui \
    git.ui \
    pushcode.ui \
    test.ui \
    ../MT2/buginfo.ui
RESOURCES += res.qrc
