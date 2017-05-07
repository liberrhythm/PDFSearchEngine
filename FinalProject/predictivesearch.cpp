#include "predictivesearch.h"


predictiveSearch::predictiveSearch()
{


}

void predictiveSearch::combo(string data)
{
    cout<<"Doing Predictive Analytics"<<endl<<endl<<"This might take a momment..."<<endl;
    string charDelete, charChange, charAdd;

    for(int i=0; i<data.size(); i++)
    {
        charDelete=data.substr(0, i) + data.substr(i+1);
        count++;
        //contains function
        if(charDelete=="")//indexinterface.contains(charDelete);
        {
            //string and int pair is added to the possible word vector
            //possibleWords.push_back(indexinterface.find(charDelete);

        }


        for(char j='a'; j<='z'; j++)
        {
            charAdd=data.substr(0, i) + j + data.substr(i+1);
            count++;
            
            //indexinterface.contains(charAdd);
            if(charAdd=="")//contains fucntion
            {
                //possibleWords.push_back(indexinterface.find(charAdd));

            }


            charChange=data.substr(0, i) + j + data.substr(i);
            count++;
           
            //indexinterface.contains(charChange);
            if(charChange=="")//contains fucntion
            {
                //possibleWords.push_back(indexinterface.find(charChange);

            }
        }
    }
    permutation(data);
    cout<<"Search engine has done predictive searches for you"<<endl;
    vecManager();
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
        //indexinterface.contains(charPermutate);
        if(charPermutate=="")//contains fucntion
        {
            //possibleWords.push_back(indexinterface.find(charPermutate);

        }


    }while(next_permutation(charPermutate.begin(),charPermutate.end()));

}

//this function will sort the vector possibleWords and returns the top 5 strings adds temVec
void predictiveSearch::vecManager()
{

    if(!possibleWords.empty()){
    //sort vector based of frequence or tf/idf
    sort(possibleWords.begin(), possibleWords.end(), [](const pair<string, int>& left, const pair<string, int>& right)
    {return left.second > right.second;});
    int count=1;
    int choice;

    cout<<endl<<"Did you mean the following terms instead?"<<endl;

    if(possibleWords.size()<=5)
    {
        for(int i=0; i<possibleWords.size(); i++)
        {
         cout<<count<<". "<<possibleWords[i].first<<endl;
         count++;
        }
    }
    else
    {
        for(int i=0; i<6; i++)
        {

         cout<<count<<". "<<possibleWords[i].first<<endl;
         count++;
        }
    }

    cout<<"If you would like to see the PDF for any of the above terms, enter the precideing number"<<endl;
    cout<<endl<<"Enter 9 to return to the main menu"<<endl;
    cin>>choice;
    if(choice < possibleWords.size())
    {
        //send search to query
    }
    else if(choice == 9)
    {
        possibleWords.clear();
        //return user to main
    }
    else
    {
        cout<<"Invalid entery! please enter the numbers listed above"<<endl;
        vecManager();

    }
    }
    else
    {
        cout<<endl<<"Oops! Predictive Search wasnt able to find any possile matchs in the Corpus, Please try a diffrent coprus"<<endl;
        //return to the main menu
    }



}









