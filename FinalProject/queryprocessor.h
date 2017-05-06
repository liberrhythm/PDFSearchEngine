#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H
#include <queue>
#include <iostream>
#include <string>

using namespace std;

class queryProcessor
{
    vector<string>results;
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
