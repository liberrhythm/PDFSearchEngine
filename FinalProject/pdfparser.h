#ifndef PDFPARSER_H
#define PDFPARSER_H

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <sys/types.h>
#include <dirent.h>
#include <algorithm>
#include <sstream>
#include "avltree.h"
#include "stopwords.h"
#include "word.h"
//#include "avlindex.h"
#include "searcher.h"
#include "indexinterface.h"

using namespace std;

class PDFParser {
    private:
        AvlTree<Word> words;
        AvlTree<string> stopWords;
        fstream file;
        vector<string> outputFiles;
        int numWordsIndexed;
    public:
        PDFParser();
        AvlTree<Word>& getWords();
        void readDirectory();
        void parsePDF(string, string);
        void insertWord(string, string);
        bool isStringBlanks(string);
        int getNumWordsIndexed();
        int getNumDocs();
        vector<string>& getOutputFiles();
};

#endif // PDFPARSER_H
