/*!
 *
 *
 * \Team Muaz and Sabrina
 *
 * \Version 1.0
 *
 * \data 2017-05-08
 *
 *
 *
 */


#include "queryprocessor.h"

queryProcessor::queryProcessor()
{
    StopWords sW;
    stopTree=sW.getStopTree();

}

queue<string>& queryProcessor::requestInput()
{
    while (!input.empty()) {
        input.pop();
    }

    cout<<"Please enter your search terms:"<<endl;
    string searchTerm;
    string buffer;
    getline(cin, buffer);
    cout << "Search query results for: " << buffer << endl;
    istringstream ss(buffer);

    while (getline( ss, buffer, ' ' ))
    {

        //changing the input words to lower case and format text
        Word w(buffer);
        searchTerm=w.getText();
        //check for stop words
        if(stopTree.contains(searchTerm)){
            if(searchTerm == "and" || searchTerm == "or" || searchTerm == "not"){
                input.push(searchTerm);
                continue;
            }
            else
            {
                cout<<"The stop word: "<<searchTerm<<" was detected please try again."<<endl;

                //if stop word detected, clear queue
                while(!input.empty()){
                    input.pop();
                }
                buffer.clear();
                requestInput();
                break;
            }
        }
        else
        {
            input.push(searchTerm);
        }
    }

    //    while(!input.empty()){
    //        cout<<input.front()<<endl;
    //        input.pop();
    //    }

    return input;
}


