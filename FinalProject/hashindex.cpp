#include "hashindex.h"

HashIndex::HashIndex() {

}

Hashtable<string, Word>& HashIndex::getWords() {
    return words;
}

void HashIndex::addWord(Word wrd) {
    words.insert(wrd.getText(), wrd);
}

Word& HashIndex::find(string str) {
    return words.find(str);
}

bool HashIndex::contains(string str) {
    return words.contains(str);
}

void HashIndex::printWords() {
    words.print();
}
