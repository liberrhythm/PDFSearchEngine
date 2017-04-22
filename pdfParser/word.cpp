#include "word.h"

Word::Word() {
    text = "";
}

Word::Word(string wrd, string file) {
    text = wrd;
    addFile(file);
}

void Word::addFile(string file) {
    fileNames.push_back(file);
}

vector<string> Word::getFiles() {
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
