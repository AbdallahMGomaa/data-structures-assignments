#pragma once
#ifndef MEETINGS_H
#define MEETINGS_H

#include <string>
#include <iostream>
using namespace std;
class Meeting{
public:
    Meeting(){}
    Meeting(string,int,int);
    string getTitle();
    void setTitle(string);
    int getDay();
    void setDay(int);
    int getHour();
    void setHour(int);
    bool operator<(Meeting);
    bool operator<=(Meeting);
    bool operator>(Meeting);
    bool operator>=(Meeting);
    bool operator==(Meeting);
    bool operator!=(Meeting);
    friend ostream& operator<<(ostream& os,const Meeting& m);
private:
    string title;
    int day;
    int hour;
};

#endif