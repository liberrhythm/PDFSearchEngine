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
        //int numDocs;
        IndexInterface* index;
        queue<string> input;
        vector<pair<string, int>> documents;
        vector<pair<string, int>> tfidfRankings;
    public:
        Searcher();
        Searcher(IndexInterface*);
        bool checkForWord(string);
        void getQuery();
        void receiveRequest(string, int);
        vector<pair<string, int>>& receiveStringRequest(string);
        vector<pair<string, int>>& calculateTFIDF(Word, int);
        string findPDFToPrint(string, vector<string>);
        void printPDF(string);
        void printResults(vector<pair<string, int>>&);


        void andQuery();
        void orQuery();
        void simpleQuery(string);
        void outPut(vector<pair<string, int>>&);
        vector<pair<string, int>>& vecUnion(vector<pair<string, int>>&, vector<pair<string, int>>&);
        vector<pair<string, int>>& vecInter(vector<pair<string, int>>&, vector<pair<string, int>>&);
        vector<pair<string, int>>& vecDiff(vector<pair<string, int>>&, vector<pair<string, int>>&);

};

#endif // SEARCHER_H
