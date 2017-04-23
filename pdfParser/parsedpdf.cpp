#include "parsedpdf.h"

ParsedPDF::ParsedPDF(const char* files) {
    DIR* corpus;
    struct dirent* dir;
    char filePath[4096];

    while ((corpus = opendir(files)) == nullptr) {
        fprintf(stderr, "Could not open directory: %s\n", files);
        exit(-1);
    }

    getStopWords();

    while ((dir = readdir(corpus)) != nullptr) {
        if (strncmp(dir->d_name, "..", 2) != 0 && strncmp(dir->d_name, ".", 1) != 0) {
            string fileName = dir->d_name;
            string fileType = fileName.substr(fileName.length()-4, fileName.length());
            if (fileType == ".pdf") {
                cout << dir->d_name << endl;
                strncpy(filePath, files, 4095);
                strncat(filePath, "/", 4095);
                strncat(filePath, dir->d_name, 4095);

                cout << filePath << endl;

                readPDF(filePath);
            }
        }
    }

    closedir(corpus);
}

void ParsedPDF::readPDF(const char* pdfName) {
    PoDoFo::PdfMemDocument pdf(pdfName);

    for (int i = 0; i < pdf.GetPageCount(); i++) {
        PoDoFo::PdfPage* page = pdf.GetPage(i);
        PoDoFo::PdfContentsTokenizer tok(page);
        const char* token = nullptr;
        PoDoFo::PdfVariant var;
        PoDoFo::EPdfContentsType type;
        while (tok.ReadNext(type, token, var)) {
            if (type == PoDoFo::ePdfContentsType_Keyword) {
                if (var.IsArray()) {
                    PoDoFo::PdfArray& a = var.GetArray();
                    for (size_t j = 0; j < a.GetSize(); j++) {
                        if (a[j].IsString()) {
                            string str(a[j].GetString().GetString());
                            string fileName(pdfName);
                            Word newWord(str, pdfName);
                            if (!stopWords.contains(newWord.getText())) {
                                words.insert(newWord);
                            }
                        }
                    }
                }
            }
        }
    }
}

void ParsedPDF::getStopWords() {
    StopWords s;
    stopWords = s.getStopTree();
}

/*
void ParsedPDF::removeStopWords(const vector<string>& stopWords) {
    vector<string> stopWords = readStopWords();
    for (int i = 0; i < stopWords.size(); i++) {
        for (int j = 0; j < words.size(); j++) {
            if (stopWords[i] == words[j]) {
                words.erase(words.begin()+j);
                j--;
            }
        }
    }
}
*/

void ParsedPDF::printWords() {
    words.printInOrder();
}


