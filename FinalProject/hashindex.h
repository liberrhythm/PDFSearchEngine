#ifndef HASHINDEX_H
#define HASHINDEX_H

#include "indexinterface.h"
#include "hashtable.h"


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
 * \ connects the hashtable with the indexinterface
 */


class HashIndex : public IndexInterface {
    private:
        Hashtable<string, Word> words;
    public:
        HashIndex();
        void addWord(Word);
        Word& find(string);
        bool contains(string);
        void printWords();
        ~HashIndex() = default;
};

#endif // HASHINDEX_H
