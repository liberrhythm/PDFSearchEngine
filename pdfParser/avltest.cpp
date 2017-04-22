#include "catch.hpp"
#include "avltree.h"
#include <string>

TEST_CASE("Avl Tree class", "[AvlTree]"){

    AvlTree<int> myTree;
    AvlTree<string> stringTree;
    AvlTree<int> headTree(30);
    headTree.insert(20);

    SECTION("Default constructor"){

        REQUIRE(myTree.isEmpty() == true);
        REQUIRE(stringTree.isEmpty() == true);

        myTree.insert(20);
        myTree.insert(10);
        stringTree.insert("sam");

        REQUIRE(myTree.isEmpty() == false);
        REQUIRE(stringTree.isEmpty() == false);

    }

    SECTION("Constructor with head"){

        REQUIRE(headTree.contains(20)==true);
        REQUIRE(headTree.findMax()==30);
        REQUIRE(headTree.findMin()==20);
    }


    SECTION("Copy constructor"){
        myTree.insert(5);
        myTree.insert(30);
        myTree.insert(40);

        AvlTree<int>copyTree(myTree);

      REQUIRE(copyTree.isEmpty()==false);
      REQUIRE(copyTree.findMax()==40);

    }

    SECTION("find"){
        myTree.insert(956);
        myTree.insert(500);

        REQUIRE(myTree.find(956)==956);
        REQUIRE(myTree.contains(956)==true);
        REQUIRE(myTree.find(500)==500);
        REQUIRE(myTree.contains(500)==true);
    }

    SECTION("findMin"){
        myTree.insert(5);
        myTree.insert(30);
        myTree.insert(40);
        myTree.insert(15);
        myTree.insert(18);

        REQUIRE(myTree.findMin()==5);

    }

    SECTION("findMax"){
        myTree.insert(5);
        myTree.insert(30);
        myTree.insert(40);
        myTree.insert(15);
        myTree.insert(18);

        REQUIRE(myTree.findMax()==40);
    }

    SECTION("Insert"){
        myTree.insert(5);
        myTree.insert(30);
        myTree.insert(20);
        myTree.insert(15);
        myTree.insert(18);
        myTree.insert(13);
        myTree.insert(4);
        myTree.insert(19);

        //REQUIRE(myTree.find(20)==20);
        REQUIRE(myTree.contains(13)==true);
        REQUIRE(myTree.contains(19)==true);
        REQUIRE(myTree.contains(4)==true);


    }

    SECTION("Contains"){

        myTree.insert(5);
        myTree.insert(30);
        myTree.insert(40);
        myTree.insert(15);
        myTree.insert(18);
        myTree.insert(13);
        myTree.insert(4);
        myTree.insert(19);

        REQUIRE(myTree.contains(15) == true);
        REQUIRE(myTree.contains(900)==false);
        REQUIRE(myTree.contains(18)==true);

    }

    SECTION("Assignment operator"){
        myTree.insert(5);
        myTree.insert(30);
        myTree.insert(40);
        myTree.insert(15);
        myTree.insert(18);
        myTree.insert(13);
        myTree.insert(4);
        myTree.insert(19);


        AvlTree<int> assiTree=myTree;

        REQUIRE(assiTree.contains(40)==true);
        REQUIRE(assiTree.contains(900)==false);
        REQUIRE(assiTree.contains(18)==true);

    }
}
