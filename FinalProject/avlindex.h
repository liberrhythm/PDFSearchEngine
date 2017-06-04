#ifndef AVLINDEX_H
#define AVLINDEX_H

#include "indexinterface.h"
#include "avltree.h"
#include "word.h"

/*!
 *
 *
 * \Team Muaz and Sabrina
 *
 * \Version 1.0
 *
 * \data 2017-05-08
 *
 * \child class that that inherets from indexInterface
 *
 * \connects the avlTree with the indexinterface
 */

class AvlIndex: public IndexInterface {
    private:
        AvlTree<Word> words;
    public:
        AvlIndex();
        void addWord(Word);
        Word& find(string);
        bool contains(string);
        void printWords();
        ~AvlIndex() = default;
};

#endif // AVLINDEX_H
