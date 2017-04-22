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

using namespace std;
using namespace PoDoFo;
using namespace Porter2Stemmer;

class ParsedPDF {
    private:
        vector<string> words;
    public:
        ParsedPDF(const char*);
        void formatString(string&);
        void clearPunctuation(string&);
        vector<string> readStopWords();
        void removeStopWords();
        void stemWords();
        void getFinalWords();
        void printContents();
};

#endif // PARSEDPDF_H
