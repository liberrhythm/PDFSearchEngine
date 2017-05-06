






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
        cout<<" in one search" <<endl;

        //searcher(input.front());//equals a vector

        //outPut();//might use or query

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



void queryProcessor::searcher(string data) //should return a vector

{

    //if(abClass.contains(data)){



    //abClass.find(data)=results;//needs fixing

    //}



}


void queryProcessor::andQuery()

{
    cout<<"and Query"<<endl;
    //we remove the first element "and" from the queue

    input.pop();

    if(input.front()=="not"){



        //remove the contents

    }

    else

    {

        //find the same types of documents

    }



    if(!input.empty())

    {

        //while the queue is not empty the function is called recurcively

        andQuery();

    }

}



void queryProcessor::orQuery()

{
    cout<<"or Query"<<endl;
    //we remove the first element "or" from the queue

    input.pop();



    if(input.front()=="not"){



        //remove the contents

    }

    else

    {

        //find the same types of documents

    }



    if(!input.empty()){

        //while the queue is not empty the function is called recurcively

        orQuery();

    }

    else if(input.empty()){



        outPut();

    }

}



void queryProcessor::outPut()
{

   // Searcher.printResults(results);
}
