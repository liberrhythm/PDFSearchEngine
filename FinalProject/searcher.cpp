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


    cout<<endl<<endl;
    cout<<"---------Results for: "<<searchWord<<"------------------"<<endl;

    if(wordTree.contains(term)){

        foundPDFNames = wordTree.find(term).getFiles();
        for(int i=0; i<foundPDFNames.size(); i++){
            cout<<foundPDFNames[i]<<endl;
        }
    }
    else {
        cout<<"This word does not exist in the specified corpus" << endl;
    }
    cout<<"---------end of results-------------------------------"<<endl<<endl;
}
