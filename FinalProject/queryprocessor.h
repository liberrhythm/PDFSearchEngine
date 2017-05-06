#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H
#include <queue>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <locale>
#include "porter2_stemmer.h"
#include "word.h"
#include "stopwords.h"
#include "avltree.h"
#include "searcher.h"

using namespace std;
using namespace Porter2Stemmer;

class queryProcessor
{
    AvlTree<string>stopTree;
    vector<pair<string, int>> results;
    queue<string> input;

public:
    queryProcessor();
    void requestInput();
    void searcher(string);
    void andQuery();
    void orQuery();
    void outPut();

};

#endif // QUERYPROCESSOR_H
