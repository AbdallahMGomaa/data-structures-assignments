
#ifndef INORD_LIST_H
#define INORD_LIST_H

template <class T>
class InOrderedList{
private:
    struct Node{
        T elem;
        Node* next;
        Node(T e){
            elem=e;
            next=nullptr;
        }
        Node(){
            next=nullptr;
        }
    };
    Node *head, *current;
    int Size;
public:
    InOrderedList();
    ~InOrderedList();
    bool insert(const T&);
    bool remove(const T&);
    int index(const T&);
    T operator[](const int&);
    int size();
    bool isEmpty();
    void print();
    bool first(T&);
    bool next(T&);
    
};

#endif
