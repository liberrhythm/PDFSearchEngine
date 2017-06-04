/*!
 *
 *
 * \Team Muaz and Sabrina
 *
 * \Version 1.0
 *
 * \data 2017-05-08
 *
 * \oop class, used to hold the string and anything associated with it
 */

#ifndef WORD_H
#define WORD_H

#include <string>
#include <locale>
#include <ostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include "avltree.h"
#include "porter2_stemmer.h"

using namespace std;
using namespace Porter2Stemmer;

class Word {

    friend ostream& operator<<(ostream&, const Word&);

    private:
        string text;
        vector<pair<string, int>> files;
        int totalFrequency;
    public:
        Word();
        Word(string);
        Word(string, string);
        Word(string, pair<string, int>);

        string getText();
        int getTotalFrequency();

        void addFile(string);
        void addFileFromIndex(pair<string, int>);
        vector<pair<string, int>>& getFiles();
        int findFile(string);
        bool operator>(const Word&);
        bool operator<(const Word&);
        bool operator==(const Word&);
        void formatString();
        void clearPunctuation();
        void stemWord();
};

#endif // WORD_H
