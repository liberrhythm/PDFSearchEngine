#include "pdfparser.h"

PDFParser::PDFParser() {

}

PDFParser::PDFParser(char* dir) {
    directory = dir;
    StopWords s;
    stopWords = s.getStopTree();
}

PDFParser::PDFParser(char* dir, AvlTree<Word>& a) {
    directory = dir;
    words = a;
}

AvlTree<Word>& PDFParser::getWords() {
    return words;
}

void PDFParser::readDirectory() {
    DIR* corpus;
    struct dirent* dir;
    char filePath[4096];

    while ((corpus = opendir(directory)) == nullptr) {
        fprintf(stderr, "Could not open directory: %s\n", directory);
        exit(-1);
    }

    int pdfCount = 0;

    while ((dir = readdir(corpus)) != nullptr) {
        if (strncmp(dir->d_name, "..", 2) != 0 && strncmp(dir->d_name, ".", 1) != 0) {
            string fileName = dir->d_name;
            string onlyFile = fileName.substr(0, fileName.length()-4);
            string fileType = fileName.substr(fileName.length()-4, fileName.length());

            if (fileType == ".pdf") {
                pdfCount++;
                strncpy(filePath, directory, 4095);
                strncat(filePath, "/", 4095);
                string dirPath = filePath;
                strncat(filePath, dir->d_name, 4095);

                string newFileName = "\"" + fileName + "\"";
                string textFile = onlyFile + ".txt";
                string outputFile = "\"" + onlyFile + ".txt" + "\"";
                outputFiles.push_back(textFile);

                string outputPath = "/home/coder/Desktop/DS/CSE2341-17S-Have-mercy/build-FinalProject-Desktop_Qt_5_8_0_GCC_64bit-Debug/";
                string command = "pdftotext " + dirPath + newFileName + " " + outputPath + outputFile;

                system(command.c_str());
                parsePDF(textFile, fileName);
            }
        }
    }

    closedir(corpus);
}

void PDFParser::parsePDF(string text, string pdfName) {
    //cout << text.c_str() << endl;
    file.open(text.c_str(), ios::in);
    if (!file) {
        cerr << "PDF to text file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    getline(file, line);
    while(!file.eof()) {
        stringstream ss(line);
        string wrd;
        while (ss >> wrd) {
            insertWord(wrd, pdfName);
        }
        getline(file, line);
    }
    file.close();
}

void PDFParser::insertWord(string str, string pdfName) {
    if (!stopWords.contains(str)) {
        Word newWord(str, pdfName);
        if (newWord.getText() != "") {
            if (!words.contains(newWord)) {
                words.insert(newWord);
            }
            else {
                words.find(newWord).addFile(pdfName);
            }
        }
    }
}

bool PDFParser::isStringBlanks(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            return false;
        }
    }
    return true;
}

int PDFParser::getNumDocs() {
    return outputFiles.size();
}

void PDFParser::printWords() {
    words.printInOrder();
}

/*
void PDFParser::requestSearch() {
    Searcher se;

    se.receiveRequest(words, "phobias");
    se.receiveRequest(words, "schunk");
}
*/
