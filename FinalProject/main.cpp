#include <iostream>
#include <podofo/podofo.h>
#include <string>
#include <vector>
#include "parsedpdf.h"
#include "avltree.h"

using namespace PoDoFo;
using namespace std;

int main(int argc, char *argv[]) {
    ParsedPDF pdfFiles(argv[1]);
    //pdfFiles.printWords();
    pdfFiles.requestSearch();
    return 0;
}



