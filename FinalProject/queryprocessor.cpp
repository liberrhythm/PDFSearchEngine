#include "queryprocessor.h"

using namespace std;

queryProcessor::queryProcessor()
{

    StopWords sW;
    stopTree=sW.getStopTree();

}


void queryProcessor::requestInput()
{

    cout<<"Please enter your search terms:"<<endl;
    string searchTerm;
    string buffer;
    getline( cin, buffer );
    istringstream ss(buffer);

    while (getline( ss, buffer, ' ' ))
    {

        //changing the input words to lower case
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


    if(input.size()==1)
    {

        //need to check for and, not, or
        results=locator.receiveStringRequest(input.front());//equals a vector
        input.pop();
        outPut();

    }

    else if(input.front()=="and")

    {

        andQuery();

    }

    else if(input.front()=="or")

    {

        orQuery();

    }

}


void queryProcessor::andQuery()
{

    //we remove the first element "and" from the queue
    input.pop();

    //while the queue is not empty, search words are implementd
    while(!input.empty()){
    if(input.front()=="not"){



    }
    else
    {

    //find the same types of documents


    }

    input.pop();

    }

    outPut();

}



void queryProcessor::orQuery()
{
    //we remove the first element "and" from the queue
    input.pop();

    //while the queue is not empty, search words are implementd
    while(!input.empty()){
    if(input.front()=="not"){



        //remove the contents

    }
    else
    {

        //find the same types of documents

    }

    input.pop();
    }

    outPut();

}



void queryProcessor::outPut()
{

    // Searcher.printResults(results);
}
