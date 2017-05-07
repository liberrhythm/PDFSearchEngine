#ifndef PREDICTIVESEARCH_H
#define PREDICTIVESEARCH_H
#include <string>
#include <vector>
#include "searcher.h"
#include <iostream>
#include <algorithm>

using namespace std;




class predictiveSearch
{

private:

    int count=0;
    vector<pair<string,int>> possibleWords;

public:

    predictiveSearch();
    void combo(string);
    void permutation(string);
    void vecManager();



};



#endif // PREDICTIVESEARCH_H
