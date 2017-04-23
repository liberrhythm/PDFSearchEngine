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
