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

/*!
 *
 *
 * \Team Muaz and Sabrina
 *
 * \Version 1.0
 *
 * \data 2017-05-08
 *
 * \takes care of the managing and holding the index
 */


using namespace std;

class IndexHandler {
    private:
        fstream f;
        IndexInterface* index;
        //AvlTree<Word> index;
        int numDocuments;
        int numWordsIndexed;
        int numWordsTotal;
        PDFParser parser;
        vector<string> txtFiles;
    public:
        IndexHandler();
        IndexInterface* returnIndex();
        vector<string> getTextFiles();
        void chooseIndex();
        void getIndex();

        bool doesIndexExist();
        void writeToIndex(AvlTree<Word>&);
        void readFromIndex();
        void clearIndex();

        int getNumDocuments();
        void printStatistics();
        void getTopWords();

};

#endif // INDEXHANDLER_H
