#ifndef List_cpp
#define List_cpp

#include "list.h"


//***************
// METODY
//***************

//Konstruktor listy
//tworzy nowa liste dwukierunkowa z jednym elementem o zadanej wartosci v
List::List(int v)
{
    Node * a= new Node;
    a->next = a;
    a->prev = a;
    a->value = v;
    head.wsk = a;
    tail.wsk = a;
    size = 1;
    a->ID=++IdElem;
    IdElem=0;
    vCopy=v;
}//List::List(int v)

//Wstawia nowy element do listy dwukierunkowej
//Element ma wartosc v i jest wstawiany za elementem wskazywanym przez iterator it
List::Pointer List::insertList(Pointer it, int v)
{
    Node * a = it.wsk;
    Node * b = new Node;
    Node * c = a->next;
    b->next = c;
    b->prev = a;
    b->value = v;
    b->ID = ++IdElem;
    c->prev = b;
    a->next = b;
    if(b->next == b)tail.wsk = b; //uaktualnij tail listy, jezeli dodajemy za ostatnim elementem
    size++;
    return it;
}//List::Pointer List::insertList(Pointer it, int v)

//Usuwa z listy dwukierunkowej element wskazywany przez iteroator it
List::Pointer List::deleteList(Pointer &it)
{
    Node * b = it.wsk;
    Node * a = b->prev;
    Node * c = b->next;
    a->next = c;
    c->prev = a;
    if(head.wsk == b) head.wsk = c; //uaktualnij head listy, jezeli usuwamy pierwszy element
    if(tail.wsk == b) tail.wsk = a;     //uaktualnij tail listy, jezeli usuwamy ostatni element
    it.wsk = a;
    delete b;
    size--;
    return it;
}//List::Pointer List::deleteList(Pointer it)

//--pokaz--obecny--
List::Pointer List::showCurrent(Pointer it)
{
    cout <<" v= "<< it.wsk->value<<" ID= "<< it.wsk->ID<<endl;
    //return it;
}//List::Pointer List::showCurrent(Pointer it)
//--pokaz--obecny--

//--skopiuj--obecny--
List::Pointer List::copy(Pointer it)
{
    vCopy=it.wsk->value;
    //return it;
}//List::Pointer List::copy(Pointer it)
//--skopiuj--obecny--


//--wklej--obecny--
List::Pointer List::paste(Pointer it)
{
    list1.insertList(it,vCopy);
    it = it.next(it);
    //return it;
}//List::Pointer List::paste(Pointer it)
//--wklej--obecny--


//Zwraca head listy dwukierunkowej
List::Pointer List::begin()
{
    return head;
}//List::Pointer List::begin()

//Zwraca tail listy dwukierunkowej
List::Pointer List::end()
{
    return tail;
}//List::Pointer List::end()

//displaya zwartosc listy dwukierunkowej
void List::display()
{
    Pointer it = head;
    cout <<"v={ ";
    for(int i = 0 ; i < size ; i++)
    {
        cout << it.wsk->value<<", ";
        it.wsk = it.wsk->next;
    }
    cout <<"}";

    it = head;
    cout <<"\nID={ ";
    for(int i = 0 ; i < size ; i++)
    {
        cout << it.wsk->ID<<",  ";
        it.wsk = it.wsk->next;
    }
    cout <<"}";

    cout <<"\nIlosc elementow= "<<size<<endl;
}//void List::display()


//Zwraca Pointer na kolejny element w liscie dwukierunkowej
List::Pointer List::Pointer::next(Pointer it)
{
    it.wsk = it.wsk->next;
    return it;
}//List::Pointer List::Pointer::next(Pointer it)



//Zwraca Pointer na element o zadanym ID
List::Pointer List::getID(int v)
{
    Pointer it = head;
    for(int i = 0 ; i < size; i++)
    {
        int x = it.wsk->ID;
        if(x == v) break;
        else it.wsk = it.wsk->next;
    }
    return it;
}//List::Pointer List::getID(int v)

//Zwraca Pointer na element o zadanej Wartosci
List::Pointer List::getVal(int v)
{
    Pointer it = head;
    for(int i = 0 ; i < size; i++)
    {
        int x = it.wsk->value;
        if(x == v) break;
        else it.wsk = it.wsk->next;
    }
    return it;
}//List::Pointer List::getID(int v)

//initialise list�
void initialise ()
{
//wstaw element 20, za pierwszym elementem
    list1.insertList(it,20);
//przesun wskazink na kolejne miejsce
    it = it.next(it);
    list1.insertList(it,30);
    it = it.next(it);
    list1.insertList(it,40);
    it = it.next(it);
    list1.insertList(it,50);
    it = it.next(it);
    list1.insertList(it,60);
    it = it.next(it);
    list1.insertList(it,70);
    it = it.next(it);
    list1.insertList(it,80);
    it = it.next(it);
    list1.insertList(it,90);
    it = it.next(it);


    list1.insertList(it,8);

    it = it.next(it);
    list1.insertList(it,12);


    cout << "\n";
}//initialise liste


#endif List_cpp
