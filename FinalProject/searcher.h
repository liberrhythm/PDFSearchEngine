#ifndef SEARCHER_H
#define SEARCHER_H
#include "avltree.h"
#include "word.h"
#include "pdfparser.h"
#include <cmath>

class Searcher {
    private:
        vector<pair<string, int>> tfidfRankings;
    public:
        Searcher(char*);
        void receiveRequest(AvlTree<Word>&, string, int);
        vector<pair<string, int>>& calculateTFIDF(Word, int);
        void printResults();
};

#endif // SEARCHER_H
