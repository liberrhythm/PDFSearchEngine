#ifndef PARSEDPDF_H
#define PARSEDPDF_H

#include <iostream>
#include <podofo/podofo.h>
#include <string>
#include <vector>
#include <istream>
#include <locale>
#include <fstream>
#include <algorithm>
#include "porter2_stemmer-master/porter2_stemmer.h"
#include "avltree.h"
#include "word.h"

using namespace std;
using namespace PoDoFo;
using namespace Porter2Stemmer;

class ParsedPDF {
    private:
        AvlTree<Word> words;
        AvlTree<string> stopWords;
    public:
        ParsedPDF(const char*);
        void formatString(string&);
        void clearPunctuation(string&);
        void readStopWords();
        //void stemWords();
        //void getFinalWords();
        //void printContents();
};

#endif // PARSEDPDF_H
