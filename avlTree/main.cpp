#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <iostream>
#include "avltree.h"

using namespace std;

int runCatchTests(int argc, char* const argv[])
{
    //This line of code causes the Catch library to
    //run the tests in the project.
    return Catch::Session().run(argc, argv);
}

int main(int argc, char *argv[])
{
    //if there is no command line argument, catch is run
    if(argc == 1){
        return runCatchTests(argc, argv);

    }

    AvlTree<int> myTree;
    AvlTree<int> headTree;
    headTree.insert(30);
    headTree.insert(20);

        myTree.insert(5);
        myTree.insert(30);
        myTree.insert(40);
        myTree.insert(15);
        myTree.insert(18);
        myTree.insert(13);
        myTree.insert(4);
        myTree.insert(19);



        AvlTree<int>copyTree=myTree;

        copyTree.printInOrder();
        myTree.printInOrder();
    return 0;
}
