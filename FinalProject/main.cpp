#include <iostream>
#include <podofo/podofo.h>
#include <string>
#include <vector>
#include <cstdlib>
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
        IndexHandler ih;
        if (choice == 1) {
            choice = printMaintenanceMenu();
            while (choice != 3) {
                switch (choice) {
                case 1:
                    if (!ih.doesIndexExist()) {
                        ih.getIndex();
                    }
                    else {
                        ih.readFromIndex();
                    }
                    break;
                case 2:
                    ih.clearIndex(); break;
                default: cout << "That is not a valid choice. Please enter another choice:" << endl; break;
                }
                choice = printMaintenanceMenu();
            }
        }
        else if (choice == 2) {
            choice = printQueryMenu();
            while (choice != 5) {
                switch (choice) {
                case 1: cout << "Select avl or hashtable" << endl; break;
                case 2: cout << "Enter search query" << endl; break;
                case 3: cout << "Print basic statistics" << endl; break;
                case 4: cout << "Do predictive analytics" << endl; break;
                default: cout << "That is not a valid choice. Please enter another choice." << endl; break;
                }
                choice = printQueryMenu();
            }
        }
        else {
            cout << "That is not a valid selection. Please enter one of the choices above." << endl;
        }
        choice = printModeMenu();
    }

    cout << "Thank you for using our search engine!" << endl;

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
    cout << "4) Predictive Analytics" << endl;
    cout << "5) Exit query mode" << endl;
    cout << "Action: ";
    int choice;
    cin >> choice;
    cout << endl;
    return choice;
}


