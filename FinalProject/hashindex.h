#ifndef HASHINDEX_H
#define HASHINDEX_H

#include "indexinterface.h"
#include "hashtable.h"

class HashIndex : public IndexInterface {
    private:
        Hashtable<string, Word> words;
    public:
        HashIndex();
        void addWord(Word);
        Word& find(string);
        bool contains(string);
        void printWords();
};

#endif // HASHINDEX_H
