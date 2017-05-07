#include <iostream>
#include <podofo/podofo.h>
#include <string>
#include <vector>
#include <cstdlib>
#include "pdfparser.h"
#include "avltree.h"
#include "indexhandler.h"
#include "searcher.h"
#include "queryprocessor.h"

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

char printModeMenu();
char printMaintenanceMenu();
char printQueryMenu();

int main(int argc, char *argv[]) {

    cout << "PDF Search Engine by Muaz and Sabrina!" << endl;

    char choice = printModeMenu();
    IndexHandler ih;
    while (choice != '3') {
        if (choice == '1') {
<<<<<<< HEAD
            char mchoice = printMaintenanceMenu();
            while (mchoice != '3') {
                switch (mchoice) {
=======
            choice = printMaintenanceMenu();
            while (choice != '3') {
                switch (choice) {
>>>>>>> ae3c28df1e3f85c18c11fe28f97bce011e4afc16
                    case '1':
                        ih.getIndex(); break;
                    case '2':
                        ih.clearIndex(); break;
                    default: cout << "That is not a valid choice. Please enter another choice:" << endl; break;
                }
                mchoice = printMaintenanceMenu();
            }
        }
        else if (choice == '2') {
<<<<<<< HEAD
            char qchoice = printQueryMenu();
            while (qchoice != '5') {
                switch (qchoice) {
                    case '1': ih.chooseIndex(); break;
                    case '2':
                        Searcher se(ih.returnIndex());
                        cin.ignore();
                        se.getQuery();
                        break;
                    case '3': ih.printStatistics(); break;
                    case '4': cout << "Do predictive search" << endl; break;
=======
            choice = printQueryMenu();
            while (choice != '5') {
                switch (choice) {
                    case '1': ih.chooseIndex(); break;
                    case '2': cout << "Enter search query" << endl; break;
                    case '3': ih.printStatistics(); break;
                    case '4': cout << "Do Predictive Search" << endl; break;
>>>>>>> ae3c28df1e3f85c18c11fe28f97bce011e4afc16
                    default: cout << "That is not a valid choice. Please enter another choice." << endl; break;
                }
                qchoice = printQueryMenu();
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

char printModeMenu() {
    cout << "Choose a mode: " << endl;
    cout << "1) Maintenance mode" << endl;
    cout << "2) Query mode" << endl;
    cout << "3) Exit search engine" << endl;

    cout << "Mode selection: ";
    char choice;
    cin >> choice;
    cout << endl;
    return choice;
}

char printMaintenanceMenu() {
    cout << "Maintenance Menu: " << endl;
    cout << "1) Add documents to the index" << endl;
    cout << "2) Clear the index" << endl;
    cout << "3) Exit maintenance mode" << endl;
    cout << "Action: ";
    char choice;
    cin >> choice;
    cout << endl;
    return choice;
}

char printQueryMenu() {
    cout << "Query mode: " << endl;
    cout << "1) Choose an index data structure" << endl;
    cout << "2) Search for a term" << endl;
    cout << "3) Print search engine statistics" << endl;
<<<<<<< HEAD
    cout << "4) Predictive search" << endl;
=======
    cout << "4) Predictive Search" << endl;
>>>>>>> ae3c28df1e3f85c18c11fe28f97bce011e4afc16
    cout << "5) Exit query mode" << endl;
    cout << "Action: ";
    char choice;
    cin >> choice;
    cout << endl;
    return choice;
}

