TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    parsedpdf.cpp \
    word.cpp \
    stopwords.cpp

LIBS += -lpodofo

DISTFILES += \
    xrayingpregnantbitches.pdf \
    ../build-FinalProject-Desktop_Qt_5_8_0_GCC_64bit-Debug/xrayingpregnantbitches.pdf \
    ../build-FinalProject-Desktop_Qt_5_8_0_GCC_64bit-Debug/StopWords

HEADERS += \
    parsedpdf.h \
    word.h \
    avltree.h \
    stopwords.h
