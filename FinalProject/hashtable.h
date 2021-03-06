#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <iomanip>
#include <functional>
#include <vector>

/*!
 *
 *
 * \Team Muaz and Sabrina
 *
 * \Version 1.0
 *
 * \data 2017-05-08
 *
 */


using namespace std;

template<class K, class V>

class Hashtable{

private:
    /*!
     *\an object of struct is used to hold the key-value pair
     */
    struct info{
        K key;
        V value;
        info(K newKey, V newValue){
            key = newKey;
            value = newValue;
        }
        K getkey(){
            return key;
        }
        V& getValue(){
            return value;
        }
    };

    /*!
     *\the hash table implements an array of vector info objects
     */
    int size;
    vector<info>* datalist;

public:
    /*!
     *\publice functions
     */
    Hashtable();
    Hashtable(int);

    Hashtable(Hashtable &rhs);
    Hashtable& operator=(Hashtable &rhs);

    ~Hashtable();

    void insert(K, V);

    V& find(K);
    bool contains(K);

    int getSize();
    bool isHashtableEmpty();

    void print();

};

/*!
 *\defult constructor initalizes the size to a predetermed number
 */
template<class K, class V>
Hashtable<K, V>::Hashtable(): size(1000000)
{
    datalist = new vector<info>[size];
}

/*!
 *\size construcor recives an int for intializing the size
 */
template<class K, class V>
Hashtable<K, V>::Hashtable(int newsize)
{
    if(newsize<20){
        size=20;
    }
    else
    {
        size=newsize;
    }
    datalist = new vector<info>[size];
}

/*!
 *\copy constructor implements a forloop to deep copy every elements
 */
template<class K, class V>
Hashtable<K, V>::Hashtable(Hashtable &rhs)
{
    size=rhs.size;
    datalist=new vector<info> [size];
    for(int i =0; i<size; i++)
    {
        datalist[i]=rhs.datalist[i];
    }
}

/*!
 *\ operator implements a forloop to deep copy every elements
 */
template<class K, class V>
Hashtable<K, V>& Hashtable<K, V>::operator=(Hashtable<K, V> &rhs)
{
    size=rhs.size;
    if(datalist !=nullptr)
    {
        delete [] datalist;
    }
    datalist=new vector<V> [size];
    for(int i =0; i<size; i++)
    {
        datalist[i]=rhs.datalist[i];
    }
    return *this;
}

/*!
 *\destructor for deleteing elements when program closes
 */
template<class K, class V>
Hashtable<K, V>::~Hashtable()
{
    delete[] datalist;
    datalist=nullptr;
}

/*!
 *\insert function recives a key vaue pair and uses the key to hash and determine where to put the value in the text
 */
template<class K, class V>
void Hashtable<K, V>::insert(K key, V value)
{
    int index = hash<K>()(key) % size;
    info obj(key, value);
    datalist[index].push_back(obj);
}


/*!
 *\function uses key, to hash it and go to the index of the hash value to look for the data
 */
template<class K, class V>
V& Hashtable<K, V>::find(K newKey)
{
    int index=hash<K>()(newKey) % size;
    for(int j=0; j<datalist[index].size(); j++)
    {
        if(datalist[index][j].getkey() == newKey){
            return datalist[index][j].getValue();
        }
    }
    //    for(int i=0; i<size; i++)
    //    {
    //        for(int j=0; j<datalist[i].size(); j++)
    //        {
    //            if((datalist[i].operator [](j)).getkey()==newKey){
    //                return datalist[i][j].getValue();
    //            }
    //        }
    //    }
    //need to throw an excpetion
}

/*!
 *\function uses key, to hash it and go to the index of the hash value to look for the data and confirm
 */
template<class K, class V>
bool Hashtable<K, V>::contains(K newKey)
{
    int index=hash<K>()(newKey) % size;
    for(int j=0; j<datalist[index].size(); j++)
    {
        if(datalist[index][j].getkey() == newKey){
            return true;
        }
    }
    return false;
    //    for(int i=0; i<size; i++)
    //    {
    //        for(int j=0; j<datalist[i].size(); j++)
    //        {
    //            if(datalist[i][j].getkey() == newKey){
    //                return true;
    //            }
    //        }
    //    }
    //    return false;
}


template<class K, class V>
int Hashtable<K, V>::getSize()
{
    return size;
}

/*!
 *\function used to detmine if the table is empty
 */
template<class K, class V>
bool Hashtable<K, V>::isHashtableEmpty()
{
    for(int i=0; i<size; i++)
    {
        if(datalist[i].size()!=0){
            return false;
        }
    }
    return true;
}

/*!
 *\function for prinitng the contents of the table
 */
template<class K, class V>
void Hashtable<K, V>::print()
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<datalist[i].size(); j++)
        {
        cout<<datalist[i][j].getValue();
        }
    }
}
#endif // HASHTABLE_H
