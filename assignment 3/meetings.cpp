#include "meetings.h"

Meeting::Meeting(string t,int d,int h){
    title = t;
    day = d;
    hour = h;
}
string Meeting::getTitle(){
    return title;
}
int Meeting::getDay(){
    return day;
}
int Meeting::getHour(){
    return hour;
}
void Meeting::setTitle(string t){
    title = t;
}
void Meeting::setDay(int d){
    day = d;
}
void Meeting::setHour(int h){
    hour = h;
}
bool Meeting::operator<(Meeting m){
    return 24*day+hour < 24*m.day+m.hour;
}
bool Meeting::operator<=(Meeting m){
    return 24*day+hour <= 24*m.day+m.hour;
}
bool Meeting::operator>(Meeting m){
    return 24*day+hour > 24*m.day+m.hour;
}
bool Meeting::operator>=(Meeting m){
    return 24*day+hour >= 24*m.day+m.hour;
}
bool Meeting::operator==(Meeting m){
    return 24*day+hour == 24*m.day+m.hour;
}
bool Meeting::operator!=(Meeting m){
    return 24*day+hour != 24*m.day+m.hour;
}
ostream& operator<<(ostream& os,const Meeting& m){
    os<<m.title<<' '<<m.day<<' '<<m.hour;
    return os;
}