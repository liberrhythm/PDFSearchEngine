//takes care of stopwords

#ifndef STREAMPARSER_H
#define STREAMPARSER_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <sys/types.h>
#include <sstream>
#include "word.h"
#include "stopwords.h"
#include "avltree.h"

using namespace std;

class StreamParser {
    private:
        string buffer;
        AvlTree<string> stopWords;
    public:
        StreamParser();
        vector<string> separateWords(string);
        bool verifyWord(string);
};

#endif // STREAMPARSER_H
