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
 * \ recives queryies from user, manuplates the data and passes it to the searcher
 */


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
private:
    AvlTree<string>stopTree;
    queue<string> input;

public:
    queryProcessor();
    queue<string>& requestInput();

};

#endif // QUERYPROCESSOR_H
