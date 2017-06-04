/*!
 *
 *
 * \Team Muaz and Sabrina
 *
 * \Version 1.0
 *
 * \data 2017-05-08
 *
 */

#include "hashindex.h"

HashIndex::HashIndex() {

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
