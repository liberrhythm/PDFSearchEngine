#include "searcher.h"
#include <iostream>
#include <vector>

using namespace std;

Searcher::Searcher(char* directory) {
    PDFParser parser(directory);
    parser.readDirectory();
    string term;
    cout << parser.getNumDocs() << endl;
    cout << "What is the term you would like to search for? ";
    cin >> term;
    while (term != "quit") {
        receiveRequest(parser.getWords(), term, parser.getNumDocs());
        tfidfRankings.clear();
        cout << "What is the term you would like to search for? ";
        cin >> term;
    }
}

void Searcher::receiveRequest(AvlTree<Word>& wordTree, string term, int numDocs) {


    cout << endl << endl;
    cout << "---------Results for: " << term << "------------------" << endl;

    if (wordTree.contains(term)) {

        //cout << wordTree.find(term);
        tfidfRankings = calculateTFIDF(wordTree.find(term), numDocs);

        cout << term << endl;

        for (int i = 0; i < tfidfRankings.size() && i < 15; i++) {
            cout << i+1 << ") ";
            cout << tfidfRankings[i].first << " " << tfidfRankings[i].second << endl;
        }
    }
    
    else {
        cout << "This word does not exist in the specified corpus" << endl;
    }
    cout << "---------end of results-------------------------------" << endl << endl;
}

vector<pair<string, int>>& Searcher::calculateTFIDF(Word wrd, int numDocs) {
    vector<pair<string, int>> files = wrd.getFiles();
    for (pair<string, int> p: files) {
        double tf = p.second;
        double idf = log2(static_cast<double>(numDocs) / static_cast<double>(files.size()));
        double tfidf = tf * idf;
        tfidfRankings.push_back(pair<string, int>(p.first, tfidf));
    }
    sort(tfidfRankings.begin(), tfidfRankings.end(), [](const pair<string, int>& left, const pair<string, int>& right)
    {return left.second > right.second;});
    return tfidfRankings;
}

void Searcher::printResults() {

}
