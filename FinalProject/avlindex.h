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
        AvlTree<Word>& getWords();
        void addWord(Word);
        Word& find(string);
        bool contains(string)=0;
        void printWords();
};

#endif // AVLINDEX_H
