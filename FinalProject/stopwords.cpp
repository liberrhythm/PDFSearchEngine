#include "stopwords.h"

StopWords::StopWords() {
    ifstream inFile;
    inFile.open("StopWords", ios::in);

    if (!inFile) {
        cerr << "Stop words file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    string wrd;
    inFile >> wrd;

    while (!inFile.eof()) {
        stopTree.insert(wrd);
        inFile >> wrd;
    }

    inFile.close();
}

AvlTree<string>& StopWords::getStopTree()
{
    return stopTree;
}
