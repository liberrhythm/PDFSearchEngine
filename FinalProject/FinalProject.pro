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
    StopWords

HEADERS += \
    parsedpdf.h \
    word.h \
    ../avlTree/avltree.h \
    ../avlTree/catch.hpp \
    avltree.h \
    stopwords.h
