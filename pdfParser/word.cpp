#include "word.h"

Word::Word() {
    text = "";
}

Word::Word(string wrd, string file) {
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
    fileNames.push_back(file);
}

vector<string>& Word::getFiles() {
    return fileNames;
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
    for (int i = 0; i < text.length(); i++) {
        if (text[i] < 97 || text[i] > 122) { //if char is not a letter
            if (text[i] != 39 || text[i] != 45) { //apostrophe and hyphen
                text.erase(i, 1);
            }
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
    output << wrd.text;
    return output;
}
