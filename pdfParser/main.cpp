#include <iostream>
#include <podofo/podofo.h>
#include <string>
#include <vector>
#include <istream>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

#include "parsedpdf.h"

using namespace PoDoFo;
using namespace std;

int main(int argc, char *argv[])
{
    DIR* corpus;
    struct dirent* dir;
    char filePath[4096];

    while ((corpus = opendir(argv[1])) == nullptr) {
        fprintf(stderr, "Could not open directory: %s\n", argv[1]);
        exit(-1);
    }

    while ((dir = readdir(corpus)) != nullptr) {
        if (strncmp(dir->d_name, "..", 2) != 0 && strncmp(dir->d_name, ".", 1) != 0) {
            string fileName = dir->d_name;
            string fileType = fileName.substr(fileName.length()-4, fileName.length());
            if (fileType == ".pdf") {
                cout << dir->d_name << endl;
                strncpy(filePath, argv[1], 4095);
                strncat(filePath, "/", 4095);
                strncat(filePath, dir->d_name, 4095);

                cout << filePath << endl;

                ParsedPDF pdf(filePath);
                //pdf.getFinalWords();
                pdf.printContents();
            }
        }
    }

    closedir(corpus);

    return 0;
}

