#include "avlindex.h"

AvlIndex::AvlIndex() {

}

AvlTree<Word>& AvlIndex::getWords() {
    return words;
}

void AvlIndex::addWord(Word wrd) {
    words.insert(wrd);
}

Word& AvlIndex::find(string str) {
    Word wrd(str);
    return words.find(wrd);
}

bool AvlIndex::contains(string str) {
    Word temp(str);
    return words.contains(temp);
}

void AvlIndex::printWords() {
    words.printInOrder();
}
