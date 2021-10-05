#include "eventPlanner.h"
int count_quotes(string s){
    int count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='"'){
            count++;
        }
    }
    return count;
}
bool EventPlanner::add(string title,int day,int hour){
    if(count_quotes(title)!=2){
        cout<<"Invalid title\n";
        return false;
    }
    else if(day<0||day>365){
        cout<<"Invalid day\n";
        return false;
    }
    else if(hour<0||hour>23){
        cout<<"Invalid hour\n";
        return false;
    }
    if(day>=1&&day<=365&&hour>=0&&hour<=23){
        Meeting meeting(title,day,hour);
        Node<Meeting>* node = bst.search(meeting);
        if(node==nullptr){
            bst.insert(meeting);
            return true;
        }
        else{
            cout<<"Conflict "<<day<<' '<<hour<<endl;
            return false;
        }
    }
    return false;
}
Meeting EventPlanner::find(int day,int hour){
    Meeting meeting("",day,hour);
    Node<Meeting>* meeting_node = bst.search(meeting);
    if(meeting_node==nullptr){
        meeting.setTitle("Empty");
        return meeting;
    }
    return meeting_node->data;
}
void EventPlanner::modify(Meeting meeting,string newTitle){
    Node<Meeting>* node = bst.search(meeting);
    node->data.setTitle(newTitle);
}
void EventPlanner::remove(Meeting meeting){
    bst.remove(meeting);
}
void EventPlanner::print(){
    bst.print();
}
bool EventPlanner::isEmpty(){
    return bst.isEmpty();
}