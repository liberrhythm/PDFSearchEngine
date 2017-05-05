#include "word.h"

Word::Word() {
    text = "";
    totalFrequency = 0;
}

Word::Word(string wrd) {
    totalFrequency = 0;
    text = wrd;
    formatString();
    clearPunctuation();
    //stemWord();
}

Word::Word(string wrd, string file) {
    totalFrequency = 0;
    text = wrd;
    formatString();
    clearPunctuation();
    //stemWord();
    addFile(file);
}

string Word::getText() {
    return text;
}

void Word::addFile(string file) {
    totalFrequency++;
    int index = findFile(file);
    if (index != -1) {
        files[index].second += 1;
    }
    else {
        files.push_back(pair<string, int>(file, 1));
    }
}

vector<pair<string, int>>& Word::getFiles() {
    return files;
}

int Word::findFile(string file) {
    for (int i = 0; i < files.size(); i++) {
        if (files[i].first == file) {
            return i;
        }
    }
    return -1;
}

bool Word::operator>(const Word& wrd) {
    return text > wrd.text;
}

bool Word::operator<(const Word& wrd) {
    return text < wrd.text;
}

bool Word::operator==(const Word& wrd) {
    return text == wrd.text;
}

void Word::formatString() {
    locale loc;
    for (string::size_type i = 0; i < text.length(); i++) {
        text[i] = tolower(text[i], loc);
    }
}

void Word::clearPunctuation() {
    for (unsigned int i = 0, len = text.size(); i < len; i++) {
        if (text[i] < 97 || text[i] > 122 || ispunct(text[i])) {
            text.erase(i--, 1);
            len = text.size();
        }
    }
}

/*
void Word::stemWord() {
    trim(text);
    stem(text);
}
*/

ostream& operator<<(ostream& output, const Word& wrd) {
    output << wrd.text << endl;
    for (pair<string, int> p: wrd.files) {
        output << p.first << "-" << p.second << endl;
    }
    return output;
}
