#include "predictivesearch.h"
#include <iostream>
#include <algorithm>

predictiveSearch::predictiveSearch()
{


}

void predictiveSearch::combo(string data)
{
    string charDelete, charChange, charAdd;

    for(int i=0; i<data.size(); i++)
    {
        charDelete=data.substr(0, i) + data.substr(i+1);
        count++;
        cout<<charDelete<<"     "<<"del "<<count<<endl;
        if(charDelete=="")//contains function
        {
            possibleWords.push_back(charDelete);
        }


        for(char j='a'; j<='z'; j++)
        {
            charAdd=data.substr(0, i) + j + data.substr(i+1);
            count++;
            cout<<charAdd<<"        "<<"add "<<count<<endl;
            if(charAdd=="")//contains fucntion
            {
                possibleWords.push_back(charAdd);
            }


            charChange=data.substr(0, i) + j + data.substr(i);
            count++;
            cout<<charChange<<"     "<<"che "<<count<<endl;
            if(charChange=="")//contains fucntion
            {
                possibleWords.push_back(charChange);
            }
        }
    }
    permutation(data);
}

//permutations was found from http://en.cppreference.com/w/cpp/algorithm/next_permutation
void predictiveSearch::permutation(string data)
{
 string charPermutate=data;

    //the string needs to be in a sorted order to get all of the permutations
    sort(charPermutate.begin(), charPermutate.end());
    do
    {
        count++;
        cout<<charPermutate<<"      "<<"per "<<count<<endl;
        if(charPermutate=="")//contains fucntion
        {
            possibleWords.push_back(charPermutate);
        }


    }while(next_permutation(charPermutate.begin(),charPermutate.end()));

}

//this function will sort the vector possibleWords and returns the top 5 strings adds temVec
vector<string> predictiveSearch::vecManager()
{
    vector<string> tempVec;
    //sort vector based of frequence or tf/idf
    //add the first 5 strings to tempVec

    /* an interface needs to output tem vec and allow the user to choose one of the words to search for
       */

    return tempVec;
}









