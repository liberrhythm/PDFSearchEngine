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
#include "avlindex.h"
#include "searcher.h"

using namespace std;

class PDFParser {
    private:
        char* directory;
        AvlTree<Word> words;
        AvlTree<string> stopWords;
        fstream file;
        vector<string> outputFiles;

    public:
        PDFParser();
        PDFParser(char*);
        PDFParser(char*, AvlTree<Word>&);
        AvlTree<Word>& getWords();
        void readDirectory();
        void parsePDF(string, string);
        void insertWord(string, string);
        bool isStringBlanks(string);
        int getNumDocs();
        void printWords();
        //void requestSearch();
};

#endif // PDFPARSER_H
