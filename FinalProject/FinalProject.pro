TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt



SOURCES += main.cpp \
    word.cpp \
    stopwords.cpp \
    searcher.cpp \
    streamparser.cpp \
    avlindex.cpp \
    pdfparser.cpp \
    indexhandler.cpp

LIBS += -lpodofo

DISTFILES += \
    xrayingpregnantbitches.pdf \
    StopWords \
    ../build-FinalProject-Desktop_Qt_5_8_0_GCC_64bit-Debug/StopWords \
    index.txt

HEADERS += \
    word.h \
    ../avlTree/avltree.h \
    ../avlTree/catch.hpp \
    avltree.h \
    stopwords.h \
    searcher.h \
    streamparser.h \
    avlindex.h \
    indexinterface.h \
    pdfparser.h \
    indexhandler.h
