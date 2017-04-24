TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt



SOURCES += main.cpp \
    parsedpdf.cpp \
    word.cpp \
    stopwords.cpp \
    searcher.cpp

LIBS += -lpodofo

DISTFILES += \
    xrayingpregnantbitches.pdf \
    StopWords \
    ../build-FinalProject-Desktop_Qt_5_8_0_GCC_64bit-Debug/StopWords

HEADERS += \
    parsedpdf.h \
    word.h \
    ../avlTree/avltree.h \
    ../avlTree/catch.hpp \
    avltree.h \
    stopwords.h \
    searcher.h
