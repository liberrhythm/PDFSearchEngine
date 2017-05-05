#ifndef INDEXINTERFACE_H
#define INDEXINTERFACE_H

#include "word.h"

class IndexInterface {
    public:
        virtual void addWord(Word)=0;
        virtual Word& find(string)=0;
        virtual bool contains(string)=0;
        virtual void printWords()=0;
};

#endif // INDEXINTERFACE_H
