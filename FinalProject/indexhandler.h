#ifndef INDEXHANDLER_H
#define INDEXHANDLER_H

#include <string>
#include <fstream>
#include "avltree.h"
#include "pdfparser.h"
#include "word.h"

using namespace std;

class IndexHandler {
    private:
        fstream f;
        AvlTree<Word> index;
        int numDocuments;
        //PDFParser parser;
    public:
        IndexHandler();
        IndexHandler(char*);
        int getNumDocuments();
        bool isIndexEmpty();
        void writeToIndex();
        void readFromIndex();
};

#endif // INDEXHANDLER_H
