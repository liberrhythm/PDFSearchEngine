TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    parsedpdf.cpp \
    ../build-FinalProject-Desktop_Qt_5_8_0_GCC_64bit-Debug/porter2_stemmer-master/porter2_stemmer.cpp \
    word.cpp

LIBS += -lpodofo

DISTFILES += \
    xrayingpregnantbitches.pdf \
    ../build-FinalProject-Desktop_Qt_5_8_0_GCC_64bit-Debug/xrayingpregnantbitches.pdf \
    ../build-FinalProject-Desktop_Qt_5_8_0_GCC_64bit-Debug/StopWords

HEADERS += \
    parsedpdf.h \
    ../build-FinalProject-Desktop_Qt_5_8_0_GCC_64bit-Debug/porter2_stemmer-master/porter2_stemmer.h \
    word.h
