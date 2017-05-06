#ifndef SEARCHER_H
#define SEARCHER_H
#include "avltree.h"
#include "word.h"
#include "pdfparser.h"
#include <cmath>

class Searcher {
    private:
        int numDocs;
        AvlTree<Word> index;
        vector<pair<string, int>> documents;
        vector<pair<string, int>> tfidfRankings;
    public:
        Searcher(AvlTree<Word>, int);
        void getQuery();
        void receiveRequest(string, int);
        vector<pair<string, int>>& calculateTFIDF(Word, int);
        string findPDFToPrint(string, vector<string>);
        void printPDF(string);
};

#endif // SEARCHER_H
