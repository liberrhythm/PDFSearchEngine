#ifndef AVLINDEX_H
#define AVLINDEX_H

#include "indexinterface.h"
#include "avltree.h"
#include "word.h"

class AvlIndex: public IndexInterface {
    private:
        AvlTree<Word> words;
    public:
        AvlIndex();
        void addWord(Word);
        Word& find(string);
        bool contains(string);
        void printWords();
};

#endif // AVLINDEX_H
