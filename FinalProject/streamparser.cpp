#include "streamparser.h"

StreamParser::StreamParser() {
    buffer = "";
    StopWords s;
    stopWords = s.getStopTree();
}

vector<string> StreamParser::separateWords(string stream) {
    vector<string> words;

    for (int i = 0; i < stream.length(); i++) {
        if (ispunct(stream[i])) {
            stream.erase(i, 1);
        }
    }

    stringstream ss(stream);
    string str;
    while (ss >> str) {
        words.push_back(str);
    }

    return words;
}

/*
vector<string>& StreamParser::separateWords(string stream) {
    vector<string> words;

    string current = "";
    for (unsigned int i = 0, len = stream.size(); i < len; i++) {
        if (buffer != "") {
            int index = 0;
            while (stream[index] != ' ' || ispunct(stream[index]) == false) {
                buffer += stream[index];
                index++;
            }

            if (verifyWord(current)) {
                words.push_back(current);
            }

            buffer = "";
        }
        else if (i == stream.size()-1 && stream[i] == '-') {
            buffer = current;
        }
        else if (stream[i] == ' ' || ispunct(stream[i])) {
            if (verifyWord(current)) {
                words.push_back(current);
            }
        }
        else {
            current += stream[i];
        }
    }
    return words;
}
*/

bool StreamParser::verifyWord(string str) {
    if (!stopWords.contains(str) && str != "") {
        return true;
    }
    return false;
}

