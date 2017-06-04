/*!
 *
 *
 * \Team Muaz and Sabrina
 *
 * \Version 1.0
 *
 * \data 2017-05-08
 *
 * \main funciton, includes part of the UI
 */


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

    /*!
     *\UI begins here, the usere is taken to the print menu part
     *
     * \most of the pasing and managing the user experiance is done in the main class
     */

    cout << "PDF Search Engine by Muaz and Sabrina!" << endl;

    char choice = printModeMenu();
    IndexHandler ih;
    while (choice != '3') {
        if (choice == '1') {
            char mchoice = printMaintenanceMenu();
            while (mchoice != '3') {
                switch (mchoice) {
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
            char qchoice = printQueryMenu();
            while (qchoice != '5') {
                switch (qchoice) {
                    case '1': ih.chooseIndex(); break;
                    case '2': {
                        Searcher se(ih.returnIndex(), ih.getNumDocuments());
                        cin.ignore();
                        se.getQuery();
                        break;
                    }
                    case '3': ih.printStatistics(); break;
                    case '4': {
                        Searcher se(ih.returnIndex(), ih.getNumDocuments());
                        se.doPredictiveSearch();
                        break;
                    }
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


/*!
 *\standard menue items are displayed and called as part of the user interface
 */
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

/*!
 *\this is a helper menue to facilitiate the loading and adjusting of the index
 */
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

/*!
 *\this is a helper menue to help with the query part of the engin
 */

char printQueryMenu() {
    cout << "Query mode: " << endl;
    cout << "1) Choose an index data structure" << endl;
    cout << "2) Search for a term" << endl;
    cout << "3) Print search engine statistics" << endl;
    cout << "4) Predictive search" << endl;
    cout << "5) Exit query mode" << endl;
    cout << "Action: ";
    char choice;
    cin >> choice;
    cout << endl;
    return choice;
}

