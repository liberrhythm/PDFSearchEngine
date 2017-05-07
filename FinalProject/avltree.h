#ifndef AVLTREE_H
#define AVLTREE_H
#include <stdexcept>
#include <iostream>
using namespace std;

//avl tree is a container class that is a binary search tree that balances itself
template<class T>
class AvlTree{

//private data memebers include internal methodes and templeted node
private:
    template<class U>
    class Node{
    public:
        U data;
        Node *left;
        Node *right;
        int height=0;
        //constructors to handel the node class
        Node(){
            left=nullptr;
            right=nullptr;
            height=0;
        }
        Node(U& newData):data(newData), left(nullptr), right(nullptr){
            height=0;
        }
        Node(U& newData,Node *newLeft, Node *newRight, int newHeight ){
            data=newData;
            left=newLeft;
            right=newRight;
            height=newHeight;
        }
        //overloaded asignemnt operator for handiling the copy constructor in the avlTree class
        void operator=(Node<U>& rhs) {
            data = rhs.data;
            if(rhs.left != nullptr){
                left = new Node<U>();
                left = rhs.left;
            }
            else{
                left = nullptr;
            }
            if(rhs.right != nullptr){
                right = new Node<U>();
                right = rhs.right;
            }
            else{
                right = nullptr;
            }
            height = rhs.height;
        }
    };
    Node<T> *root;
    int max(int, int);
    int height(Node<T>*);
    void clean(Node<T>*);
    void insert(T, Node<T>*&);
    void printInOrder(Node<T>*);
    bool contains(T, Node<T>*);
    Node<T>* copy(Node<T>*&);
    void rotateLeft(Node<T>*&);
    void rotateRight(Node<T>*&);
    void doubleRight(Node<T>*&);
    void doubleLeft( Node<T>*&);
    void outputInOrder(Node<T>*&, ostream&);
    T& find(T,  Node<T>*);



public:
    AvlTree();
    AvlTree(T);
    AvlTree(AvlTree &rhs);
    ~AvlTree();
    AvlTree<T>& operator=(AvlTree<T>&);
    void clean();
    void insert(T);
    void printInOrder();
    bool isEmpty();
    bool contains(T);
    T& find(T);
    void outputInOrder(ostream&);

};
//Defult Constructor
template<class T>
AvlTree<T>::AvlTree(){
    root = nullptr;
}
//Copy constructor takes in another tree and assignes all of the elements of the rhs to the current tree
template<class T>
AvlTree<T>::AvlTree(AvlTree<T>& rhs){
      root = nullptr;
    //if the right hand tree is not a null pointer
    if(this != &rhs)
    {
        //the current elements of the tree are cleaned and then the root of the rhs tree is copied
        clean();
        //root=new Node<T>;
        //root->operator=(*rhs.root);
        root=copy(rhs.root);
    }
}
//head constructor for elements a tree starting with one element
template<class T>
AvlTree<T>::AvlTree(T data){
    root = nullptr;
    insert(data);
}
//Destractor (rule of three)
template<class T>
AvlTree<T>::~AvlTree()
{
    clean();
}
//overloaded assignment operatior, used to handel deep copy, same as copy constructor
template<class T>
AvlTree<T>& AvlTree<T>::operator=(AvlTree<T>& rhs)
{
    if(this != &rhs)
    {
        clean();
        //root=new Node<T>;
        //root->operator=(*rhs.root);
        root=copy(rhs.root);
    }
    return *this;
}
//copy function creats a new node with the copy of the passed in root
template<class T>
AvlTree<T>::Node<T>* AvlTree<T>::copy(Node<T>*& node)
{
    if(node!=nullptr){
        Node<T>* zleft = copy( node->left );
        Node<T>* zright = copy( node->right );
        return new Node<T>(node->data, zleft, zright, node->height);
    }
    else if(node==nullptr)
    {
        return nullptr;
    }
}
//public find function
template<class T>
T& AvlTree<T>::find(T data)
{
    return find(data, root);
}
//private find function returns the data by reference
template<class T>
T& AvlTree<T>::find(T data, Node<T>* node)
{
    //find function uses a while loop to eterate the tree to find the desiered node
    while(node != nullptr){
        if(data < node->data)
            node = node->left;
        else if(node->data < data)
            node = node->right;
        else
            return node->data;
    }
    throw out_of_range("Element requested is not in Tree");
}
template<class T>
void AvlTree<T>::clean()
{
    clean(root);
}
template<class T>
void AvlTree<T>::clean(Node<T>* node)
{
    Node<T> * cur;
    if(node != nullptr){
        if(node->left != nullptr){
            clean(node->left);
        }
        if(node->right != nullptr){
            clean(node->right);
        }
        cur=node;
        delete node;
    }
    node=nullptr;
}
template<class T>
bool AvlTree<T>::isEmpty()
{
    if(root == nullptr)
    {
        return true;
    }
    else
        return false;
}
template<class T>
void AvlTree<T>::insert(T x)
{
    insert(x,root);
}
template<class T>
bool AvlTree<T>::contains(T data)
{
    return contains(data, root);
}
template<class T>
bool AvlTree<T>::contains(T data, Node<T>* node)
{
    while(node != nullptr)
        if(data < node->data)
            node = node->left;
        else if(node->data < data)
            node = node->right;
        else
            return true;
    return false;
}
template<class T>
int AvlTree<T>::height(Node<T> *node)
{
    if(node==nullptr)
    {
        return -1;
    }
    else
        return node->height;
}
template<class T>
int AvlTree<T>::max(int leftSide, int rightSide)
{
    if(leftSide > rightSide){
        return leftSide;
    }
    else
        return rightSide;
}
template<class T>
void AvlTree<T>::printInOrder()
{
    printInOrder(root);
}
template<class T>
void AvlTree<T>::printInOrder(Node<T>* node)
{
    if(node!=nullptr){
        printInOrder(node->left);
        cout<<node->data<<" "<<endl;
        printInOrder(node->right);
    }

    if (isEmpty()) {
        cout << "tree is empty";
    }
}

template<class T>
void AvlTree<T>:: outputInOrder(Node<T>*& node, ostream& output)
{
    if(node!=nullptr){
        outputInOrder(node->left, output);
        output<<node->data;
        outputInOrder(node->right, output);
    }
}

template<class T>
void AvlTree<T>:: outputInOrder(ostream& output)
{
    outputInOrder(root, output);
}

//the following functions are based on what we disscused in class and AVL handout
template<class T>
void AvlTree<T>::insert(T newData, Node<T>*& node)
{
    if( node == nullptr ){
        node=new Node<T>(newData);
    }
    //if element is the same it is inserted to the left of the node
    else if(newData < node->data)
    {
        insert(newData, node->left);
        if( height(node->left) - height(node->right) == 2 ){
            if(newData < node->left->data){
                rotateLeft(node);//case1
            }
            else
                doubleLeft(node);//case2
        }
    }
    else if(node->data < newData)
    {
        insert(newData, node->right);
        if( height(node->right) - height(node->left) == 2 ){
            if(node->right->data < newData){
                rotateRight(node);//case 4
            }
            else
                doubleRight(node);//case 3
        }
    }//we need an empty else to handel if the data is the same
    node->height = max( height( node->left ), height( node->right ) ) + 1;//updating height
}
template<class T>
void AvlTree<T>::rotateLeft(Node<T>*& node1)
{
    Node<T> *node2 = node1->left;
    node1->left = node2->right;
    node2->right = node1;
    node1->height = max(height( node1->left), height(node1->right)) + 1;
    node2->height = max(height( node2->left), node1->height) + 1;
    node1 = node2;
}
template<class T>
void AvlTree<T>::rotateRight(Node<T>*& node1)
{
    Node<T> *node2 = node1->right;
    node1->right = node2->left;
    node2->left = node1;
    node1->height = max(height(node1->left), height( node1->right)) + 1;
    node2->height = max(height(node2->right), node1->height) + 1;
    node1 = node2;
}
template<class T>
void AvlTree<T>::doubleRight(Node<T>*& node1)
{
    rotateLeft( node1->right );
    rotateRight( node1 );
}
template<class T>
void AvlTree<T>::doubleLeft( Node<T>*& node2 )
{
    rotateRight(node2->left);
    rotateLeft(node2);
}


#endif // AVLTREE_H
