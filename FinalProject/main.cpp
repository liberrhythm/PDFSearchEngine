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

//IndexHandler ih(argv[1]);
//ih.writeToIndex();
//IndexHandler ih;
//ih.readFromIndex();

//Searcher se(argv[1]);
//IndexHandler ih(argv[1]);
//PDFParser pdfFiles(argv[1]);
//pdfFiles.readDirectory();
//pdfFiles.requestSearch();

int printModeMenu();
int printMaintenanceMenu();
int printQueryMenu();

int main(int argc, char *argv[]) {    
    cout << "PDF Search Engine by Muaz and Sabrina!" << endl;

    int choice = printModeMenu();
    while (choice != 3) {
        if (choice == 1) {
            choice = printMaintenanceMenu();
            while (choice != 3) {
                cout << "maintenance" << endl;
                choice = printMaintenanceMenu();
            }
        }
        else if (choice == 2) {
            choice = printQueryMenu();
            while (choice != 4) {
                cout << "query" << endl;
                choice = printQueryMenu();
            }
        }
        else {
            cout << "That is not a valid selection. Please enter one of the choices above." << endl;
        }
        choice = printModeMenu();
    }

    cout << "Thank you for using our search engine!";

    return 0;
}

int printModeMenu() {
    cout << "Choose a mode: " << endl;
    cout << "1) Maintenance mode" << endl;
    cout << "2) Query mode" << endl;
    cout << "3) Exit search engine" << endl;
    cout << "Mode selection: ";
    int choice;
    cin >> choice;
    cout << endl;
    return choice;
}

int printMaintenanceMenu() {
    cout << "Maintenance Menu: " << endl;
    cout << "1) Add documents to the index" << endl;
    cout << "2) Clear the index" << endl;
    cout << "3) Exit maintenance mode" << endl;
    cout << "Action: ";
    int choice;
    cin >> choice;
    cout << endl;
    return choice;
}

int printQueryMenu() {
    cout << "Query mode: " << endl;
    cout << "1) Choose an index data structure" << endl;
    cout << "2) Search for a term" << endl;
    cout << "3) Print search engine statistics" << endl;
    cout << "4) Exit query mode" << endl;
    cout << "Action: ";
    int choice;
    cin >> choice;
    cout << endl;
    return choice;
}


