#ifndef PARSEDPDF_H
#define PARSEDPDF_H

#include <iostream>
#include <podofo/podofo.h>
#include <string>
#include <stack>
#include <fstream>
#include <istream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <sys/types.h>
#include <dirent.h>
#include <algorithm>
#include "avltree.h"
#include "searcher.h"
#include "word.h"
#include "stopwords.h"

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
        void extractText(PdfMemDocument*, PdfPage*, const char*);
        void getStopWords();
        void addWord(string, const char*);
        void printWords();
        void requestSearch();
};

#endif // PARSEDPDF_H
