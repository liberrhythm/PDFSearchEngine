/*!
 *
 *
 * \Team Muaz and Sabrina
 *
 * \Version 1.0
 *
 * \data 2017-05-08
 *
 */


#include "searcher.h"
#include <iostream>
#include <vector>

Searcher::Searcher() {

}

Searcher::Searcher(IndexInterface* ih, int docs) {
    index = ih;
    numDocs = docs;
}

void Searcher::doPredictiveSearch() {
    isPredictive = true;
    predictiveSearch ps(index);
    ps.combo();
    string str = ps.vecManager();
    if (str != "") {
        simpleQuery(str);
    }
    isPredictive = false;
}

void Searcher::getQuery() {
    queryProcessor qr;
    input = qr.requestInput();

    if (input.size()==1) {
        vector<pair<string, int>> data;
        if (checkForWord(input.front())) {
            data=receiveStringRequest(input.front());//equals a vector
        }

        input.pop();
        printResults(data);
    }
    else if(input.front()=="and")
    {

        andQuery();

    }
    else if(input.front()=="or")
    {
        orQuery();
    }
    else {
        notQuery();
    }
}

bool Searcher::checkForWord(string term) {
    if (index->contains(term)) {
        return true;
    }
    else {
        cout << term << " does not exist in the corpus" << endl;
        return false;
    }
}

vector<pair<string, int>> Searcher::receiveStringRequest(string term) {
    Word wrd = index->find(term);
    return wrd.getFiles();
}

void Searcher::printResults(vector<pair<string, int>> data)
{
    if (!data.empty()) {
        calculateTFIDF(data);

        for (int i = 0; i < tfidfRankings.size() && i < 15; i++) {
            cout << i+1 << ") ";
            cout << tfidfRankings[i].first << " " << tfidfRankings[i].second << endl;
        }

        cout << endl << endl;

        int tfidfSize = tfidfRankings.size();
        for (int i = 0; i < tfidfSize; i++) {
            tfidfRankings.pop_back();
        }

        printPDF();
    }
    else {
        cout << "No results found for search query" << endl << endl;
    }
}

void Searcher::calculateTFIDF(vector<pair<string, int>> files) {
    for (pair<string, int> p: files) {
        double tf = p.second;
        double idf = log2(static_cast<double>(numDocs) / static_cast<double>(files.size()));
        double tfidf = tf * idf;
        tfidfRankings.push_back(pair<string, int>(p.first, tfidf));
    }
    sort(tfidfRankings.begin(), tfidfRankings.end(), [](const pair<string, int>& left, const pair<string, int>& right)
    {return left.second > right.second;});
}

void Searcher::printPDF() {
    string doc;
    cout << "Which pdf would you like to view?" << endl;

    if (isPredictive) {
        cin.ignore();
    }

    getline(cin, doc);

    doc = doc.substr(0, doc.length()-4);
    doc += ".txt";

    cout << doc << endl;

    ifstream inFile;
    inFile.open(doc, ios::in);

    if (!inFile) {
        cerr << "PDF file requested could not be opened for reading" << endl;
    }
    else {
        string line;
        getline(inFile, line);
        while (!inFile.eof()) {
            cout << line << endl;
            getline(inFile, line);
        }
    }
    inFile.close();
}

void Searcher::simpleQuery(string s) {

    vector<pair<string, int>> data;
    if (checkForWord(s)) {
        data=receiveStringRequest(s);//equals a vector
    }

    //input.pop();
    printResults(data);
}

void Searcher::notQuery() {
    vector<pair<string, int>> temp;
    vector<pair<string, int>> results;

    while(!input.empty()){

        if(input.front() == "not"){
            input.pop();
            if (checkForWord(input.front())) {
                temp=receiveStringRequest(input.front());
                if(!results.empty()){
                    results=vecDiff(results, temp);
                }
            }
        }
        else {
            if (checkForWord(input.front())) {
                temp=receiveStringRequest(input.front());
                if(results.empty()){
                    results=temp;
                }
            }
        }
        input.pop();
    }

    printResults(results);

}

void Searcher::andQuery() {
    vector<pair<string, int>> temp;
    vector<pair<string, int>> results;

    bool wordExists = true;

    //we remove the first element "and" from the queue
    input.pop();

    //while the queue is not empty, search words are implementd
    while(!input.empty()){

        if(input.front()=="not"){
            input.pop();
            if (checkForWord(input.front())) {
                temp=receiveStringRequest(input.front());
                if(!results.empty()){
                    results=vecDiff(results, temp);
                }
            }
        }
        else {
            if (checkForWord(input.front())) {
                temp=receiveStringRequest(input.front());
                if(results.empty()){
                    results=temp;
                }
                else {
                    results=vecInter(results, temp);
                }
            }
            else {
                wordExists = false;
            }
        }

        input.pop();
        if (wordExists == false) {
            int resultsSize = results.size();
            for (int i = 0; i < resultsSize; i++) {
                results.pop_back();
            }
            break;
        }
    }

    printResults(results);
}



void Searcher::orQuery() {
    vector<pair<string, int>> results;
    vector<pair<string, int>> temp;

    //we remove the first element "and" from the queue
    input.pop();

    //while the queue is not empty, search words are implementd
    while(!input.empty()) {

        if(input.front()=="not") {
            input.pop();
            if (checkForWord(input.front())) {
                temp=receiveStringRequest(input.front());
                if(!results.empty()){
                    results=vecDiff(results, temp);
                }
            }
        }
        else {
            if (checkForWord(input.front())) {
                temp=receiveStringRequest(input.front());
                if(results.empty()) {
                    results=temp;
                }
                else {
                    results=vecUnion(results, temp);
                }
            }
        }
        input.pop();
    }

    printResults(results);
}

vector<pair<string, int>> Searcher::vecUnion(vector<pair<string, int>>& overall, vector<pair<string, int>>& temp)
{
    for(int i=0; i<overall.size(); i++){
        for(int j=0; j<temp.size(); j++){
            if(overall[i].first==temp[j].first){
                overall[i].second+=temp[j].second;
                temp.erase(temp.begin()+j);
            }
        }
    }

    for (pair<string, int> p: temp) {
        overall.push_back(p);
    }

    return overall;
}

vector<pair<string, int>> Searcher::vecDiff(vector<pair<string, int>>& overall, vector<pair<string, int>>& temp)
{
    for(int i=0; i<overall.size(); i++){
        for(int j=0; j<temp.size(); j++){
            if(overall[i].first==temp[j].first){
                overall.erase(overall.begin()+i);
                temp.erase(temp.begin()+j);
            }
        }
    }

    return overall;
}

vector<pair<string, int>> Searcher::vecInter(vector<pair<string, int>>& overall, vector<pair<string, int>>& temp)
{
    vector<pair<string, int>> final;
    vector<pair<string, int>>::iterator it;


    for(int i=0; i<overall.size(); i++){
        for(int j=0; j<temp.size(); j++){
            if(overall[i].first==temp[j].first){
                overall[i].second+=temp[j].second;
                final.push_back( make_pair(overall[i].first,overall[i].second));
            }
        }
    }

    return final;
}
