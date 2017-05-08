#ifndef SEARCHER_H
#define SEARCHER_H
//#include "queryprocessor.h"
#include "avltree.h"
#include "hashtable.h"
#include "word.h"
#include "pdfparser.h"
#include "indexinterface.h"
#include "queryprocessor.h"
#include <queue>
#include <cmath>

using namespace std;

class Searcher {
    private:
        IndexInterface* index;
        queue<string> input;
        int numDocs;
        vector<pair<string, int>> tfidfRankings;

    public:
        Searcher();
        Searcher(IndexInterface*, int);
        bool checkForWord(string);
        void getQuery();
        void receiveRequest(string, int);
        vector<pair<string, int>> receiveStringRequest(string);
        void calculateTFIDF(vector<pair<string, int>>);
        //string findPDFToPrint(string);
        void printPDF();
        void printResults(vector<pair<string, int>>);

        void notQuery();
        void andQuery();
        void orQuery();
        void simpleQuery(string);
        //void outPut(vector<pair<string, int>>);
        vector<pair<string, int>> vecUnion(vector<pair<string, int>>&, vector<pair<string, int>>&);
        vector<pair<string, int>> vecInter(vector<pair<string, int>>&, vector<pair<string, int>>&);
        vector<pair<string, int>> vecDiff(vector<pair<string, int>>&, vector<pair<string, int>>&);

};

#endif // SEARCHER_H
