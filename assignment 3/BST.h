#pragma once
#ifndef BST_H
#define BST_H

template <class T>
struct Node{
    T data;
    Node* left,*right;
    Node(T);
};

template <class T>
class BST{
private:
    int degree;
    Node<T>* root;
    void insert(Node<T>*,T);
    void print(Node<T>* node);
    Node<T>* search(Node<T>*,T);
    Node<T>* remove(Node<T>*,T);
    Node<T>* findMin(Node<T>*);
    Node<T>* findMax();
    Node<T>* empty(Node<T>*);
public:
    BST();
    ~BST();
    bool isEmpty();
    void insert(T);
    Node<T>* search(T);
    void print();
    void remove(T);
    
};

#endif