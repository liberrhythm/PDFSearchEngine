#ifndef AVLTREE_H
#define AVLTREE_H
#include <stdexcept>
#include <iostream>

using namespace std;

template<class T>
class AvlTree{

private:

    template<class U>
    class Node{

    public:
        U data;
        Node *left;
        Node *right;
        int height=0;

        Node(){

            left=nullptr;
            right=nullptr;
            height=0;

        }

        Node(U& newData):data(newData), left(nullptr), right(nullptr){

            height=0;

        }

        void operator=(Node<U>& rhs) {
            data = rhs.data;
            if(rhs.left != nullptr){
                left = new Node<U>;
                left = rhs.left;
            }
            else{
                left = nullptr;
            }
            if(rhs.right != nullptr){
                right = new Node<U>;
                right = rhs.right;
            }
            else{
                right = nullptr;
            }
            height = rhs.height;
        }

    };

    Node<T> *root;

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

    T find(T);
    T findMin();
    T findMax();



private:
    int max(int, int);
    int height(Node<T>*);

    void clean(Node<T>*);
    void insert(T, Node<T>*&);
    void printInOrder(Node<T>*);

    bool contains(T, Node<T>*);
    Node<T>* copy(Node<T>*&);

    void rotateWithLeftChild(Node<T>*&);
    void rotateWithRightChild(Node<T>*&);
    void doubleWithRightChild(Node<T>*&);
    void doubleWithLeftChild( Node<T>*&);

    T find(T, Node<T>*);
    Node<T>* findMax(Node<T>*);
    Node<T>* findMin(Node<T>*);


};


template<class T>
AvlTree<T>::AvlTree(){

    root = nullptr;
}

template<class T>
AvlTree<T>::AvlTree(AvlTree<T>& rhs){

    root = nullptr;
    *this=rhs;
}

template<class T>
AvlTree<T>::AvlTree(T data){

    root = nullptr;
    insert(data);

}

template<class T>
AvlTree<T>::~AvlTree()
{

    //delete root;
    //clean();

}

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


template<class T>
AvlTree<T>::Node<T>* AvlTree<T>::copy(Node<T>*& node)
{
    if(node==nullptr){

        return nullptr;
    }

    insert(node->data);
    copy(node->left);
    copy(node->right);

    return node;

}

template<class T>
T AvlTree<T>::find(T data)
{

    return find(data, root);

}

template<class T>
T AvlTree<T>::find(T data, Node<T>* node)
{
    //might need to throw and exception


    while( node != nullptr ){
        if( data < node->data )
            node = node->left;
        else if( node->data < data )
            node = node->right;
        else
            return node->data;
    }
    throw out_of_range("Element requested does is not in Tree");

}


template<class T>
void AvlTree<T>::clean()
{

    clean(root);

}

template<class T>
void AvlTree<T>::clean(Node<T>* node)
{

    Node<T> * cur = node;
     while ( cur != nullptr ){
         Node<T> * next = node->right;
         delete cur;
         cur = next;
     }
     node = nullptr;


//    if(node != nullptr){
//        if(node->left != nullptr){

//            clean(node->left);
//        }
//        if(node->right != nullptr){

//            clean(node->right);

//        }
//        delete node;
//    }
//    node=nullptr;
}

template<class T>
T AvlTree<T>::findMin()
{

    if(isEmpty()){
        throw out_of_range("AvlTree is empty");
    }

    return findMin(root)->data;
}

template<class T>
T AvlTree<T>::findMax()
{

    if(isEmpty()){
        throw out_of_range("AvlTree is empty");
    }

    return findMax(root)->data;
}

template<class T>
bool AvlTree<T>::isEmpty()
{

    return root == nullptr;

}

template<class T>
AvlTree<T>::Node<T>* AvlTree<T>::findMax(Node<T>* node)
{
    if( node == nullptr )

        return nullptr;

    if( node != nullptr )

        while( node->right != nullptr )

            node = node->right;

    return node;
}


template<class T>
AvlTree<T>::Node<T>* AvlTree<T>::findMin(Node<T>* node)
{
    if( node == nullptr )

        return nullptr;

    if( node->left == nullptr )

        return node;

    return findMin( node->left );
}


template<class T>
void AvlTree<T>::insert(T x)
{

    insert(x,root);

}


template<class T>
void AvlTree<T>::insert(T newData, Node<T>*& node)
{

    if( node == nullptr ){

        node=new Node<T>(newData);

    }
    else if(newData < node->data)
    {
        insert(newData, node->left);

        if( height(node->left) - height(node->right) == 2 ){

            if(newData < node->left->data){

                rotateWithLeftChild(node);
            }
            else
                doubleWithLeftChild(node);
        }
    }
    else if(node->data < newData)
    {
        insert(newData, node->right);

        if( height(node->right) - height(node->left) == 2 ){

            if(node->right->data < newData){

                rotateWithRightChild(node);
            }
            else
                doubleWithRightChild(node);
        }
    }

    //we do nothing if it is a double
    node->height = max( height( node->left ), height( node->right ) ) + 1;
}

template<class T>
bool AvlTree<T>::contains(T data)
{

    return contains(data, root);

}

template<class T>
bool AvlTree<T>::contains(T data, Node<T>* node)
{
    while( node != nullptr )

        if( data < node->data )
            node = node->left;

        else if( node->data < data )
            node = node->right;

        else
            return true;

    return false;

}

template<class T>
int AvlTree<T>::height(Node<T> *node)
{

    return node==nullptr ? -1 : node->height;

}

template<class T>
int AvlTree<T>::max(int lhs, int rhs)
{

    return lhs > rhs ? lhs : rhs;

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

}

template<class T>
void AvlTree<T>::rotateWithLeftChild(Node<T>*& node1)
{
    Node<T> *node2 = node1->left;
    node1->left = node2->right;
    node2->right = node1;
    node1->height = max(height( node1->left), height(node1->right)) + 1;
    node2->height = max(height( node2->left), node1->height) + 1;
    node1 = node2;
}

template<class T>
void AvlTree<T>::rotateWithRightChild(Node<T>*& node1)
{
    Node<T> *node2 = node1->right;
    node1->right = node2->left;
    node2->left = node1;
    node1->height = max(height(node1->left), height( node1->right)) + 1;
    node2->height = max(height(node2->right), node1->height) + 1;
    node1 = node2;
}

template<class T>
void AvlTree<T>::doubleWithRightChild(Node<T>*& node1)
{
    rotateWithLeftChild( node1->right );
    rotateWithRightChild( node1 );
}

template<class T>
void AvlTree<T>::doubleWithLeftChild( Node<T>*& node2 )
{
    rotateWithRightChild(node2->left);
    rotateWithLeftChild(node2);
}

#endif // AVLTREE_H
