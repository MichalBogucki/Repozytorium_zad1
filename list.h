#ifndef List_h
#define List_h

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

//Deklaracja klasy listy dwukierunkowej
class List
{
    public:
    class Node
    {
        public:
        Node * next;
        Node * prev;
        int value;
        int ID;
    };
    class Pointer
    {
        public:
        Node * wsk;
        Pointer next(Pointer it);
    };
    List(int v);
    void display();
    Pointer head;
    Pointer tail;
    Pointer insertList(Pointer it, int v);
    Pointer deleteList(Pointer &it);
    Pointer showCurrent(Pointer it);
    Pointer begin();
    Pointer end();
    Pointer getID(int v);
    Pointer getVal(int v);
    int size, IdElem;
};
//uwtorz liste z elementem o wartosci 10
    List list1(10);

//pobierz wskaznik na pierwszy element listy
    List::Pointer it = list1.begin();

void initialise ();

#endif List_h
