#ifndef SEARCHER_H
#define SEARCHER_H
//#include "queryprocessor.h"
#include "avltree.h"
#include "hashtable.h"
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
        Searcher();
        Searcher(AvlTree<Word>, int);
        void getQuery();
        void receiveRequest(string, int);
        vector<pair<string, int>>& receiveStringRequest(string);
        vector<pair<string, int>>& calculateTFIDF(Word, int);
        string findPDFToPrint(string, vector<string>);
        void printPDF(string);
        void printResults(vector<pair<string, int>>& );
};

#endif // SEARCHER_H
