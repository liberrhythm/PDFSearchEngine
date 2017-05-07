#ifndef INDEXHANDLER_H
#define INDEXHANDLER_H

#include <string>
#include <fstream>
#include <stdio.h>
#include "avltree.h"
#include "avlindex.h"
#include "hashindex.h"
#include "pdfparser.h"
#include "word.h"

using namespace std;

class IndexHandler {
    private:
        fstream f;
        IndexInterface* index;
        //AvlTree<Word> index;
        int numDocuments;
        PDFParser parser;
    public:
        IndexHandler();
        IndexInterface* returnIndex();
        void chooseIndex();
        void getIndex();
        int getNumDocuments();
        bool doesIndexExist();
        void writeToIndex(AvlTree<Word>&);
        void readFromIndex();
        void clearIndex();
        void printStatistics();
};

#endif // INDEXHANDLER_H
