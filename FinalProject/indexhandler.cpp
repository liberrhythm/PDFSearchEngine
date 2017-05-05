#include "indexhandler.h"

IndexHandler::IndexHandler() {

}

IndexHandler::IndexHandler(char* directory) {
    PDFParser parser(directory);
    parser.readDirectory();
    index = parser.getWords();
    numDocuments = parser.getNumDocs();
}

int IndexHandler::getNumDocuments() {
    return numDocuments;
}

bool IndexHandler::isIndexEmpty() {
    f.open("index.txt", ios::in);
    if (!f) {
        cerr << "Persistent index could not be opened for reading" << endl;
        exit(EXIT_FAILURE);
    }
    return f.peek() == ifstream::traits_type::eof();
}

void IndexHandler::uploadIndex() {
    ofstream of;
    of.open("index.txt", ios::out);
    if (!of) {
        cerr << "Persistent index could not be opened for writing" << endl;
        exit(EXIT_FAILURE);
    }

    //of << index;

    of.close();
}


