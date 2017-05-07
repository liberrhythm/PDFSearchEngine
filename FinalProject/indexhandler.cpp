#include "indexhandler.h"

IndexHandler::IndexHandler() {

}

void IndexHandler::chooseIndex() {
    int choice;

    cout << "1) AVL tree" << endl;
    cout << "2) Hash table" << endl;
    cout << "3) Return to maintenance menu" << endl;
    cout << "Action: ";
    cin >> choice;

    while (choice != 3) {
        if (choice == 1) {
            index = new AvlIndex;
            readFromIndex();
        }
        else if (choice == 2) {
            index = new HashIndex;
            readFromIndex();
        }
        else {
            cout << "That is not a valid index option. Please select AVL or hash.";
        }
    }
}

void IndexHandler::getIndex() {
    parser.readDirectory();
    writeToIndex(parser.getWords());
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
    f.close();
    return true;
}

void IndexHandler::writeToIndex(AvlTree<Word>& words) {
    f.open("index.txt", ios::app);
    if (!f) {
        cerr << "Persistent index could not be opened for writing" << endl;
        exit(EXIT_FAILURE);
    }

    words.outputInOrder(f);

    f.close();
}

void IndexHandler::readFromIndex() {
    f.open("index.txt", ios::in);

    if (doesIndexExist()) {
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

            index->addWord(entry);
            cout << entry;
            f >> word;
        }

        index->printWords();
    }



    f.close();
}

void IndexHandler::clearIndex() {
    f.open("index.txt", ios::in);

    if (!f) {
        cerr << "Persistent index does not exist" << endl;
    }
    else {
        f.close();
        if (remove("index.txt") != 0) {
            perror("Error deleting file");
        }
        else {
            puts("File successfully deleted");
        }
    }
}

void IndexHandler::printStatistics() {
    cout << "Number of words indexed: " << parser.getNumWordsIndexed() << endl;
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

