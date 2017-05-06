#include "queryprocessor.h"

#include <sstream>

#include <vector>

#include <locale>



using namespace std;



queryProcessor::queryProcessor()

{



}



void queryProcessor::requestInput()

{

    cout<<"Please enter your search terms:"<<endl;

    string searchTerm;

    string buffer;

    getline( cin, buffer );



    istringstream ss(buffer);



    while (getline( ss, searchTerm, ' ' ))

    {

        //changing the input words to lower case

        locale tool;

        for (int i=0; i<searchTerm.length(); ++i){

           searchTerm[i]=tolower(searchTerm[i],tool);

        }



        //stem the searchTerm



        //check for stop words

        //if stop word detected, clear queue

        //output proper message, call the requestInput function

//        if(abClass.contains(searchTerm))

//        {

//            cout<<"The stop word: "<<searchTerm<<"was detected please try again."<<endl;

//            while(!input.empty()){

//                input.pop();

//            }

//            requestInput();



//        }



//        else

        {



            input.push(searchTerm);



        }

    }





    if(input.size()==1)

    {



        searcher(input.front());//equals a vector

        outPut();//might use or query



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

    //we remove the first element "and" from the queue

    input.pop();

    if(input.front()=="not"){



        //remove the contents

    }

    else

    {

        //find the same types of documents

    }



    if(input.empty()!=false)

    {

        //while the queue is not empty the function is called recurcively

        andQuery();

    }

}



void queryProcessor::orQuery()

{

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

    for(int i=0; i<results.size(); i++){

        cout<<results[i]<<endl;

    }

}
