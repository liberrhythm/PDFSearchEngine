#include "searcher.h"
#include <iostream>
#include <vector>

using namespace std;
searcher::searcher()
{

}

void searcher::receiveRequest(AvlTree<Word>& wordTree, string searchWord)
{
    vector<string> foundPDFNames;

    Word term(searchWord);

    foundPDFNames = wordTree.find(term).getFiles();

    cout<<"---------Results for: "<<searchWord<<"------------------"<<endl;
    for(int i=0; i<foundPDFNames.size(); i++){
        cout<<foundPDFNames[i]<<endl;
    }
    cout<<"---------end of results-------------------------------"<<endl<<endl;
}
