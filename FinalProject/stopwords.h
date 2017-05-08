/*!
 *
 *
 * \Team Muaz and Sabrina
 *
 * \Version 1.0
 *
 * \data 2017-05-08
 *
 * \ used to read and hold stop words
 */




#ifndef STOPWORDS_H
#define STOPWORDS_H
#include "avltree.h"
#include <fstream>

class StopWords {
    private:
        AvlTree<string> stopTree;
    public:
        StopWords();
        AvlTree<string>& getStopTree();
};

#endif // STOPWORDS_H
