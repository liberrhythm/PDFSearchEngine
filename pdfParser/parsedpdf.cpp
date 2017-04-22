#include "parsedpdf.h"

ParsedPDF::ParsedPDF(const char* pdfName) {
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
                            words.push_back(str);
                        }
                    }
                }
            }
        }
    }
}

void ParsedPDF::formatString(string& str) {
    locale loc;
    for (string::size_type i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i], loc);
    }
}

void ParsedPDF::clearPunctuation(string& str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < 97 || str[i] > 122) { //if char is not a letter
            if (str[i] != 39 || str[i] != 45) { //apostrophe and hyphen
                str.erase(i, 1);
            }
        }
    }
}

vector<string> ParsedPDF::readStopWords() {
    ifstream inFile;
    inFile.open("StopWords", ios::in);

    if (!inFile) {
        cerr << "Stop words file could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    vector<string> stopWords;
    string wrd;
    inFile >> wrd;

    while (!inFile.eof()) {
        stopWords.push_back(wrd);
        inFile >> wrd;
    }

    inFile.close();
    return stopWords;
}

void ParsedPDF::removeStopWords() {
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

void ParsedPDF::stemWords() {
    for (string& wrd: words) {
        trim(wrd);
        stem(wrd);
    }
}

void ParsedPDF::getFinalWords() {
    for (string& str: words) {
        formatString(str);
        clearPunctuation(str);
    }
    removeStopWords();
    //stemWords();
}

void ParsedPDF::printContents() {
    for (string str: words) {
        cout << str << endl;
    }
}
