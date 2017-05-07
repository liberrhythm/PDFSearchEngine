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
        vector<pair<string, int>> data=locator.receiveStringRequest(input.front());//equals a vector
        input.pop();
        outPut(data);

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

    vector<pair<string, int>> temp;
    vector<pair<string, int>> results;

    //we remove the first element "and" from the queue
    input.pop();

    //while the queue is not empty, search words are implementd
    while(!input.empty()){

        if(input.front()=="not"){

            input.pop();
            temp=locator.receiveStringRequest(input.front());

            if(results.empty()){
            //we do nothing if the vector is empty

            }
            else
            {

                results=vecDiff(results, temp);

            }

        }
        else
        {

            temp=locator.receiveStringRequest(input.front());

            if(results.empty()){

                results=temp;
            }
            else
            {
                results=vecInter(results, temp);
            }
        }

        input.pop();
    }

    outPut(results);

}



void queryProcessor::orQuery()
{

    vector<pair<string, int>> results;
    vector<pair<string, int>> temp;

    //we remove the first element "and" from the queue
    input.pop();

    //while the queue is not empty, search words are implementd
    while(!input.empty()){

        if(input.front()=="not"){

            input.pop();
            temp=locator.receiveStringRequest(input.front());

            if(results.empty()){
            //we do nothing if the vector is empty
            }
            else
            {
                results=vecDiff(results, temp);
            }
        }
        else
        {
            temp=locator.receiveStringRequest(input.front());

            if(results.empty()){

                results=temp;
            }
            else
            {
                results=vecUnion(results, temp);
            }
        }

        input.pop();
    }

    outPut(results);

}

vector<pair<string, int>>&  queryProcessor::vecUnion(vector<pair<string, int>>& overall, vector<pair<string, int>>& temp)
{

    vector<pair<string, int>> final;
    vector<pair<string, int>>::iterator it;

    for(int i=0; i<overall.size(); i++){
        for(int j=0; j<temp.size(); j++){
            if(overall[i].first==temp[j].first){
                overall[i].second+=temp[j].second;
                temp.erase(temp.begin()+j);
            }
        }
    }

    sort(overall.begin(), overall.end(), [](const pair<string, int>& left, const pair<string, int>& right)
    {return left.first > right.first;});
    sort(temp.begin(), temp.end(), [](const pair<string, int>& left, const pair<string, int>& right)
    {return left.first > right.first;});

    it=set_union(overall.begin(), overall.end(), temp.begin(), temp.end(), final.begin(),
                 [](const pair<string, int>& left, const pair<string, int>& right)
    {return left.first > right.first;});
    final.resize(it-final.begin());


    return final;
}

vector<pair<string, int>>&  queryProcessor::vecDiff(vector<pair<string, int>>& overall, vector<pair<string, int>>& temp)
{
    vector<pair<string, int>> final;
    vector<pair<string, int>>::iterator it;

    sort(overall.begin(), overall.end(), [](const pair<string, int>& left, const pair<string, int>& right)
    {return left.first > right.first;});
    sort(temp.begin(), temp.end(), [](const pair<string, int>& left, const pair<string, int>& right)
    {return left.first > right.first;});

    it=set_difference(overall.begin(), overall.end(), temp.begin(), temp.end(), final.begin(),
                      [](const pair<string, int>& left, const pair<string, int>& right)
                        {return left.first > right.first;});
    final.resize(it-final.begin());

    return final;
}

vector<pair<string, int>>&  queryProcessor::vecInter(vector<pair<string, int>>& overall, vector<pair<string, int>>& temp)
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

void queryProcessor::outPut(vector<pair<string, int>>& data)
{

    locator.printResults(data);
}
