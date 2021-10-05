#include "inord_list.h"
#include <iostream>
using namespace std;

template <class T>
InOrderedList<T>::InOrderedList(){
    Size=0;
    head=nullptr;
    current=head;
}

template <class T>
InOrderedList<T>::~InOrderedList(){
    Node* p=head, *temp=p;
    while(p!=nullptr){
        temp=p;
        p=p->next;
        delete temp;
    }
}

template <class T>
bool InOrderedList<T>::insert(const T& e){
    Node* addedNode = new Node(e);
    if(!addedNode){
        return false;
    }
    if(head==nullptr){
        head=addedNode;
        current=head;
    }
    else{
        Node* p=head,*prev=nullptr;
        while(p!=nullptr&&p->elem<e){
            prev=p;
            p=p->next;
        }
        if(prev==nullptr){
            addedNode->next=p;
            head=addedNode;
        }
        else{
            prev->next=addedNode;
            addedNode->next=p;
        }
    }
    Size++;
    return true;
}

template <class T>
bool InOrderedList<T>::remove(const T& e){
    Node *p=head, *prev=nullptr;
    while(p!=nullptr&&p->elem!=e){
        prev=p;
        p=p->next;
    }
    if(p==nullptr){
        return false;
    }
    if(prev==nullptr&&p==head){
        head=head->next;
        delete p;
    }
    else{
        prev->next=p->next;
        delete p;        
    }
    Size--;
    return true;
}

template <class T>
int InOrderedList<T>::index(const T& e){
    Node* p=head;
    int i=0;
    while(p!=nullptr&&p->elem!=e){
        p=p->next;
        i++;
    }
    return p!=nullptr?i:-1;
}

template <class T>
T InOrderedList<T>::operator[](const int& i){
    if(i<0||i>Size){
        throw std::out_of_range("inordered list out of range");
    }
    else{
        int j=0;
        Node* p=head;
        while(p!=nullptr&&j<i){
            p=p->next;
            j++;
        }
        return p->elem;
    }
}

template <class T>
int InOrderedList<T>::size(){
    return Size;
}

template <class T>
bool InOrderedList<T>::isEmpty(){
    return Size==0;
}

template <class T>
void InOrderedList<T>::print(){
    Node* p=head;
    while(p!=nullptr){
        cout<<p->elem<<' ';
        p=p->next;
    }
    cout<<endl;
}

template <class T>
bool InOrderedList<T>::first(T& e){
    if(head==nullptr){
        return false;
    }
    else{
        current=head;
        e=current->elem;
        return true;
    }
}

template <class T>
bool InOrderedList<T>::next(T& e){
    if(current->next==nullptr){
        return false;
    }
    else{
        current=current->next;
        e=current->elem;
        return true;
    }
}

