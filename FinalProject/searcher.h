#ifndef SEARCHER_H
#define SEARCHER_H
#include "avltree.h"
#include "word.h"



class searcher
{
public:
    searcher();
    void receiveRequest(AvlTree<Word>&, string);

};

#endif // SEARCHER_H
