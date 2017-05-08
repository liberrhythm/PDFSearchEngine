#include "predictivesearch.h"

predictiveSearch::predictiveSearch(IndexInterface* ih) {
    index = ih;
    cout<<"Doing Predictive Analytics"<<endl<<endl;
    cout << "What word would you like to search?" << endl;
    cin >> data;
    cout << endl << "This might take a moment..."<<endl;
}

void predictiveSearch::combo()
{
    string charDelete, charChange, charAdd;

    for(int i=0; i<data.size(); i++)
    {
        charDelete=data.substr(0, i) + data.substr(i+1);
        count++;
        //contains function
        if (index->contains(charDelete)) {
            //string and int pair is added to the possible word vector
            Word wrd = index->find(charDelete);

            if (!doesWordExist(wrd.getText())) {
                pair<string, int> p(wrd.getText(), wrd.getTotalFrequency());
                possibleWords.push_back(p);
            }

        }


        for(char j='a'; j<='z'; j++)
        {
            charAdd=data.substr(0, i) + j + data.substr(i+1);
            count++;

            //contains function
            if (index->contains(charAdd)) {
                //string and int pair is added to the possible word vector
                Word wrd = index->find(charAdd);

                if (!doesWordExist(wrd.getText())) {
                    pair<string, int> p(wrd.getText(), wrd.getTotalFrequency());
                    possibleWords.push_back(p);
                }

            }


            charChange=data.substr(0, i) + j + data.substr(i);
            count++;

            //contains function
            if (index->contains(charChange)) {
                //string and int pair is added to the possible word vector
                Word wrd = index->find(charChange);

                if (!doesWordExist(wrd.getText())) {
                    pair<string, int> p(wrd.getText(), wrd.getTotalFrequency());
                    possibleWords.push_back(p);
                }

            }
        }
    }
    permutation();
    cout<<"Search engine has done predictive searches for you"<<endl;
}

//permutations was found from http://en.cppreference.com/w/cpp/algorithm/next_permutation
void predictiveSearch::permutation()
{
    string charPermutate=data;

    //the string needs to be in a sorted order to get all of the permutations
    sort(charPermutate.begin(), charPermutate.end());
    do
    {
        count++;

        //contains function
        if (index->contains(charPermutate)) {
            //string and int pair is added to the possible word vector
            Word wrd = index->find(charPermutate);

            if (!doesWordExist(wrd.getText())) {
                pair<string, int> p(wrd.getText(), wrd.getTotalFrequency());
                possibleWords.push_back(p);
            }
        }

    }while(next_permutation(charPermutate.begin(),charPermutate.end()));

}

//this function will sort the vector possibleWords and returns the top 5 strings adds temVec
string predictiveSearch::vecManager() {
    if(!possibleWords.empty()){
        //sort vector based of frequence or tf/idf
        sort(possibleWords.begin(), possibleWords.end(), [](const pair<string, int>& left, const pair<string, int>& right)
        {return left.second > right.second;});
        int choice;

        cout<<endl<<"Did you mean the following terms instead?"<<endl;

        if(possibleWords.size()<=5)
        {
            for(int i=0; i<possibleWords.size(); i++)
            {
                cout << i+1 << ") " << possibleWords[i].first << endl;
            }
        }
        else
        {
            for(int i=0; i<5; i++) {
                cout << i+1 << ") " << possibleWords[i].first << endl;
            }
        }

        cout << "Enter a number to see results for any of the above terms: ";
        cin >> choice;
        cout << endl;
        if (choice < possibleWords.size()) {
            string str = possibleWords[choice-1].first;
            return str;
        }
        else {
            possibleWords.clear();
        }
    }
    else {
        cout << "Oops! Predictive Search wasn't able to find any possible matches in the corpus." << endl;
        //return to the main menu
    }
    return "";
}

bool predictiveSearch::doesWordExist(string str) {
    for (pair<string, int> p: possibleWords) {
        if (p.first == str) {
            return true;
        }
    }
    return false;
}









