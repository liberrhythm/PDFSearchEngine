#include "searcher.h"
#include <iostream>
#include <vector>

using namespace std;

Searcher::Searcher(AvlTree<Word> words, int docs) {
    index = words;
    numDocs = docs;
}

Searcher::Searcher() {

}

void Searcher::getQuery() {

    //queryProcessor qr;
    //qr.requestInput();

//    string term;
//    cout << "What would you like to search for? ";
//    getline(cin, term);
//    receiveRequest(term, numDocs);
//    tfidfRankings.clear();
}

vector<pair<string, int>>& Searcher::receiveStringRequest(string term) {


}

void Searcher::printRequest(vector<pair<string, int>>& data)
{

}

void Searcher::receiveRequest(string term, int numDocs) {

    cout << endl << endl;
    cout << "----------Results for: " << term << "----------" << endl;

    if (index.contains(term)) {

        //cout << wordTree.find(term);
        tfidfRankings = calculateTFIDF(index.find(term), numDocs);

        cout << term << endl;

        for (int i = 0; i < tfidfRankings.size() && i < 15; i++) {
            cout << i+1 << ") ";
            cout << tfidfRankings[i].first << " " << tfidfRankings[i].second << endl;
        }
    }
    
    else {
        cout << "This word does not exist in the specified corpus" << endl;
    }
    cout << "----------end of results----------" << endl << endl;
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

string Searcher::findPDFToPrint(string pdf, vector<string> outputFiles) {
    string doc;

    pdf = pdf.substr(pdf.length()-4, pdf.length());

    for (int i = 0; i < outputFiles.size(); i++) {
        string txtFile = outputFiles[i];
        txtFile = txtFile.substr(txtFile.length()-4, txtFile.length());
        if (pdf == txtFile) {
            doc = outputFiles[i];
            return doc;
        }
    }
}

void Searcher::printPDF(string doc) {
    ifstream inFile;
    inFile.open(doc, ios::in);

    if (!inFile) {
        cerr << "PDF file requested could not be opened for reading" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    getline(inFile, line);
    while (!inFile.eof()) {
        cout << line;
        getline(inFile, line);
    }

    inFile.close();
}
