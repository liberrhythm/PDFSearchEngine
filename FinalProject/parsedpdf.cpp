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

    int pdfCount = 0;

    while ((dir = readdir(corpus)) != nullptr) {
        if (strncmp(dir->d_name, "..", 2) != 0 && strncmp(dir->d_name, ".", 1) != 0) {
            string fileName = dir->d_name;
            string fileType = fileName.substr(fileName.length()-4, fileName.length());
            if (fileType == ".pdf") {
                //cout << dir->d_name << endl;
                strncpy(filePath, files, 4095);
                strncat(filePath, "/", 4095);
                strncat(filePath, dir->d_name, 4095);

                cout << filePath << endl;
                try {
                    readPDF(filePath);
                }
                catch (PdfError& e) {
                    fprintf (stderr, "Error: file could not be processed\n");
                    e.PrintErrorMsg();
                    //return e.GetError();
                }
                pdfCount++;
                //cout << endl << endl << endl << "HOW MANY PDFS: " << pdfCount << endl << endl << endl;

                //printWords();
            }
        }
    }

    //printWords();

    closedir(corpus);
}

void ParsedPDF::readPDF(const char* pdfName) {  
    if (!pdfName) {
        PODOFO_RAISE_ERROR(ePdfError_InvalidHandle);
    }

    PoDoFo::PdfMemDocument pdf(pdfName);

    for (int i = 0; i < pdf.GetPageCount(); i++) {
        PoDoFo::PdfPage* page = pdf.GetPage(i);
        this->extractText(&pdf, page, pdfName);
    }
}

void ParsedPDF::extractText(PdfMemDocument* pdf, PdfPage* page, const char* pdfName) {
    const char* token = nullptr;
    PdfVariant var;
    EPdfContentsType type;

    PdfContentsTokenizer tokenizer(page);
    stack<PdfVariant> stack;

    bool bTextBlock = false;

    while (tokenizer.ReadNext(type, token, var)) {
        if (type == ePdfContentsType_Keyword ) {
            if (strcmp(token, "l") == 0 || strcmp(token, "m") == 0) {
                stack.pop();
                stack.pop();
            }
            else if (strcmp(token, "BT" ) == 0) {
                bTextBlock = true;
            }
            else if (strcmp(token, "ET") == 0 ) {
                if (!bTextBlock) {
                    fprintf( stderr, "WARNING: Found ET without BT\n" );
                }
            }

            if (bTextBlock) {
                if (strcmp(token, "Tj") == 0 || strcmp(token, "'") == 0) {
                    string str(stack.top().GetString().GetString());
                    addWord(str, pdfName);
                    stack.pop();
                }
                else if (strcmp(token, "\"") == 0 ) {
                    string str(stack.top().GetString().GetString());
                    addWord(str, pdfName);
                    stack.pop();
                    stack.pop(); // remove char spacing from stack
                    stack.pop(); // remove word spacing from stack
                }
                else if (strcmp(token, "TJ") == 0 ) {
                    PdfArray array = stack.top().GetArray();
                    stack.pop();

                    for (int i = 0; i < static_cast<int>(array.GetSize()); i++) {
                        if (array[i].IsString()) {
                            string str(array[i].GetString().GetString());
                            addWord(str, pdfName);
                        }
                    }
                }
            }
        }
        else if (type == ePdfContentsType_Variant) {
            stack.push(var);
        }
        else {
            //Should be impossible because type has to be keyword or variant
            PODOFO_RAISE_ERROR(ePdfError_InternalLogic);
        }
    }
}

void ParsedPDF::getStopWords() {
    StopWords s;
    stopWords = s.getStopTree();
}

void ParsedPDF::addWord(string str, const char* pdfName) {
    if (!stopWords.contains(str) && str != "") {
        Word newWord(str, pdfName);
        if (!words.contains(newWord)) {
            words.insert(newWord);
        }
        else {
            Word existingWord = words.find(newWord);
            bool pdfFound = false;
            for (string file: existingWord.getFiles()) {
                if (file == pdfName) {
                    pdfFound = true;
                }
            }
            if (pdfFound == false) {
                words.find(newWord).getFiles().push_back(pdfName);
            }
        }
    }
}

void ParsedPDF::printWords() {
    words.printInOrder();
}

void ParsedPDF::requestSearch() {
    searcher se;

    se.receiveRequest(words, "the southeastern university and college coalition for engineering");
    se.receiveRequest(words, "vation");
    se.receiveRequest(words, "selfregulation of learning and");
    se.receiveRequest(words, "and emotion");
    se.receiveRequest(words, "psychological review");
    se.receiveRequest(words, "journal of women and minorities in science and");
    se.receiveRequest(words, "social cognitive perspective");
}
