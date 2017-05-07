#ifndef HASHINDEX_H
#define HASHINDEX_H

#include "indexinterface.h"
#include "hashtable.h"

class HashIndex : public IndexInterface {
    private:
        Hashtable<string, Word> words;

    public:
        HashIndex();
        Hashtable<string, Word>& getWords();
        void addWord(Word);
        Word& find(string);
        bool contains(string)=0;
        void printWords();
};

#endif // HASHINDEX_H
