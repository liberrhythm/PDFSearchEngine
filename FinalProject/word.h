#ifndef WORD_H
#define WORD_H

#include <string>
#include <locale>
#include <ostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include "porter2_stemmer.h"

using namespace std;

class Word {

    friend ostream& operator<<(ostream&, const Word&);

    private:
        string text;
        vector<string> fileNames;
    public:
        Word();
        Word(string, string);
        string getText();
        void addFile(string);
        vector<string>& getFiles();
        bool operator>(const Word&);
        bool operator<(const Word&);
        bool operator==(const Word&);
        void formatString();
        void clearPunctuation();
        //void stemWord();
};

#endif // WORD_H
