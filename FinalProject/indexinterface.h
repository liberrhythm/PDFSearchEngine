/*!
 *
 *
 * \Team Muaz and Sabrina
 *
 * \Version 1.0
 *
 * \data 2017-05-08
 *
 * \ pure virutal class for inhrtance between either hashtable or AVl tree
 */


#ifndef INDEXINTERFACE_H
#define INDEXINTERFACE_H

#include "word.h"

class IndexInterface {
    public:
        virtual void addWord(Word)=0;
        virtual Word& find(string)=0;
        virtual bool contains(string)=0;
        virtual void printWords()=0;
        virtual ~IndexInterface() = default;
};

#endif // INDEXINTERFACE_H
