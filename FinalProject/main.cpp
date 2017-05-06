#include <iostream>
#include <podofo/podofo.h>
#include <string>
#include <vector>
#include "pdfparser.h"
#include "avltree.h"
#include "indexhandler.h"
#include "searcher.h"

using namespace PoDoFo;
using namespace std;

int main(int argc, char *argv[]) {
    //IndexHandler ih(argv[1]);
    //ih.writeToIndex();


    IndexHandler ih;
    ih.readFromIndex();


    //Searcher se(argv[1]);
    //IndexHandler ih(argv[1]);
    //PDFParser pdfFiles(argv[1]);
    //pdfFiles.readDirectory();
    //pdfFiles.requestSearch();
    return 0;
}



