#include "BST.h"
#include <iostream>
using namespace std;

template <class T>
Node<T>::Node(T x){
    data = x;
    left = nullptr;
    right = nullptr;
}

template <class T>
BST<T>::BST(){
    root = nullptr;
    degree = 0;
}
template <class T>
void BST<T>::insert(T elem){
    if(root==nullptr){
        root = new Node<T>(elem);
    }
    else{
        insert(root,elem);
    } 
    degree++;
}
template <class T>
void BST<T>::insert(Node<T>* node,T elem){
    if(node!=nullptr){
        if(elem<=node->data){
            if(node->left == nullptr){
                node->left = new Node<T>(elem);
            }
            else{
                insert(node->left,elem);
            }
        }
        else if(elem>node->data){
            if(node->right == nullptr){
                node->right = new Node<T>(elem);
            }
            else{
                insert(node->right,elem);
            }
        }
    }
}
template <class T>
bool BST<T>::isEmpty(){
    return degree==0;
}
template <class T>
void BST<T>::print(){
    print(this->root);
}
template <class T>
void BST<T>::print( Node<T>* node){
    if(node!=nullptr){
        print(node->left);
        cout<<node->data<<endl;
        print(node->right);
    }
}
template <class T>
Node<T>* BST<T>::search(T x){
    return search(root,x);
}
template <class T>
Node<T>* BST<T>::search(Node<T>* node,T x){
    if(node!=nullptr){
        if(node->data==x){
            return node;
        }
        else if(node->data>x){
            return search(node->left,x);
        }
        else if(node->data<x){
            return search(node->right,x);
        }
    }
    return nullptr;
}
template <class T>
void BST<T>::remove(T elem){
    remove(root,elem);
    degree--;
}
template <class T>
Node<T>* BST<T>::findMin(Node<T>* node){
    Node<T>* p = node;
    if(p!=nullptr){
        while(p->left!=nullptr){
            p=p->left;
        }
    }
    return p;
}
template <class T>
Node<T>* BST<T>::findMax(){
    Node<T>* p = root;
    if(p!=nullptr){
        while(p->right!=nullptr){
            p=p->right;
        }
    }
    return p;
}
template <class T>
Node<T>* BST<T>::remove(Node<T>* node,T elem){
    Node<T> *temp;
    if(node==nullptr){
        return nullptr;
    }
    if(elem<node->data){
        node->left = remove(node->left,elem);
    }
    else if(elem>node->data){
        node->right = remove(node->right,elem);
    }
    else if(node->left&&node->right){
        temp = findMin(node->right);
        node->data = temp->data;
        node->right = remove(node->right,node->data);
    }
    else{
        temp = node;
        if(node->left==nullptr){
            node = node->right;
        }
        else if(node->right==nullptr){
            node = node->left;
        }
        delete temp;
    }
    return node;
}
template <class T>
BST<T>::~BST(){
    empty(root);
}
template <class T>
Node<T>* BST<T>::empty(Node<T>* node){
    if(node==nullptr) return nullptr;
    empty(node->left);
    empty(node->right);
    delete node;
    return nullptr;
}