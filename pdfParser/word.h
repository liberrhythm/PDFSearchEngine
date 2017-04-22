#ifndef WORD_H
#define WORD_H
#include <string>
#include <vector>

using namespace std;

class Word {
    private:
        string text;
        vector<string> fileNames;
    public:
        Word();
        Word(string, string);
        void addFile(string);
        vector<string> getFiles();
        bool operator>(const Word&);
        bool operator<(const Word&);
        bool operator==(const Word&);
};

#endif // WORD_H
