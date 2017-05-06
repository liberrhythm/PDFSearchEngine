#include "indexhandler.h"

IndexHandler::IndexHandler() {
    parser.readDirectory();
    index = parser.getWords();
    numDocuments = parser.getNumDocs();
}

int IndexHandler::getNumDocuments() {
    return numDocuments;
}

bool IndexHandler::doesIndexExist() {
    f.open("index.txt", ios::in);
    if (!f) {
        cerr << "Persistent index could not be opened for reading" << endl;
        return false;
    }
    return true;
}

void IndexHandler::writeToIndex() {
    f.open("index.txt", ios::out);
    if (!f) {
        cerr << "Persistent index could not be opened for writing" << endl;
        exit(EXIT_FAILURE);
    }

    index.outputInOrder(f);

    f.close();
}

void IndexHandler::readFromIndex() {
    f.open("index.txt", ios::in);

    string word;
    int numFiles;
    f >> word;

    while (!f.eof()) {
        Word entry(word);
        f >> numFiles;
        int frequency;
        string pdf;
        for (int i = 0; i < numFiles; i++) {
            f >> frequency;
            getline(f, pdf);
            entry.addFileFromIndex(pair<string, int>(pdf, frequency));
        }
        index.insert(entry);
        cout << entry;
        f >> word;
    }

    index.printInOrder();

    f.close();
}

void IndexHandler::clearIndex() {
    if (remove("index.txt") != 0) {
        perror("Error deleting file");
    }
    else {
        puts("File successfully deleted");
    }
}

/*
 * while (!f.eof()) {
        Word entry(word);
        getline(f, line);
        stringstream linestream(line);
        string elem;
        string pdf;
        int frequency;

        int elemCount = 0;
        while (linestream >> elem) {
            elemCount++;
            if (elemCount % 2 == 1) {
                pdf = elem;
            }
            else {
                frequency = atoi(elem.c_str());
                entry.addFileFromIndex(pair<string, int>(pdf, frequency));
            }
        }

        index.insert(entry);
        f >> word;
    }
    */

