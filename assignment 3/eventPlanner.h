#pragma once
#ifndef EVENTPLANNER_H
#define EVENTPLANNER_H

#include "BST.h"
#include "BST.cpp"
#include "meetings.h"
// #include "meetings.cpp"

class EventPlanner{
private:
    BST<Meeting> bst;
public:
    bool add(string,int,int);
    Meeting find(int,int);
    void modify(Meeting,string);
    void remove(Meeting);
    void print();
    bool isEmpty();
};

#endif