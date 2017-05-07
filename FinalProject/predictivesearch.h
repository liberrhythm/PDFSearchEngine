#ifndef PREDICTIVESEARCH_H
#define PREDICTIVESEARCH_H
#include <string>
#include <vector>


using namespace std;




class predictiveSearch
{

private:

    int count=0;
    vector<string> possibleWords;

public:

    predictiveSearch();
    void combo(string);
    void permutation(string);
    vector<string> vecManager();



};



#endif // PREDICTIVESEARCH_H
