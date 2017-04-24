#ifndef PARSEDPDF_H
#define PARSEDPDF_H

#include <iostream>
#include <podofo/podofo.h>
#include <string>
#include <fstream>
#include <istream>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <algorithm>
#include "avltree.h"
#include "word.h"
#include "stopwords.h"
#include "searcher.h"

using namespace std;
using namespace PoDoFo;
using namespace Porter2Stemmer;

class ParsedPDF {
    private:
        AvlTree<Word> words;
        AvlTree<string> stopWords;
    public:
        ParsedPDF(const char*);
        void readPDF(const char*);
        void getStopWords();
        void printWords();
        void requestSearch();

        //void removeStopWords(const vector<string>&);
};

#endif // PARSEDPDF_H
