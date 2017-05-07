#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H
#include <queue>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <locale>
#include "word.h"
#include "stopwords.h"
#include "avltree.h"
#include <algorithm>
#include "searcher.h"

using namespace std;

class queryProcessor
{
    Searcher locator;
    AvlTree<string>stopTree;
    queue<string> input;


public:
    queryProcessor();
    void requestInput();
    void andQuery();
    void orQuery();
    void simpleQuery(string);
    void outPut(vector<pair<string, int>>&);
    vector<pair<string, int>>& vecUnion(vector<pair<string, int>>&, vector<pair<string, int>>&);
    vector<pair<string, int>>& vecInter(vector<pair<string, int>>&, vector<pair<string, int>>&);
    vector<pair<string, int>>& vecDiff(vector<pair<string, int>>&, vector<pair<string, int>>&);
};

#endif // QUERYPROCESSOR_H
