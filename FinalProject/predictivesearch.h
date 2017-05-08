/*!
 *
 *
 * \Team Muaz and Sabrina
 *
 * \Version 1.0
 *
 * \data 2017-05-08
 *
 *
 * \predictive search uses diffrent combination of words to searh the corpus
 */




#ifndef PREDICTIVESEARCH_H
#define PREDICTIVESEARCH_H
#include <string>
#include <vector>
#include "searcher.h"
#include "indexinterface.h"
#include <iostream>
#include <algorithm>

using namespace std;

class predictiveSearch {
private:
    int count=0;
    string data;
    IndexInterface* index;
    vector<pair<string,int>> possibleWords;

public:
    predictiveSearch(IndexInterface*);
    void combo();
    void permutation();
    string vecManager();
    bool doesWordExist(string);
};



#endif // PREDICTIVESEARCH_H
