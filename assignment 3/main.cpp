#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "eventPlanner.h"
// #include "eventPlanner.cpp"

using namespace std;

void split_to_vector(vector<string>&,string );
bool is_number(string);

int main(int argc,char** argv){
    if(argc!=2){
        cout<<"Incorrect number of arguments\n";
        return 0;
    }
    string commandFileName=argv[1];
    fstream commandFile;
    commandFile.open(commandFileName);
    if(commandFile.fail()){
        cout << "File not found\n";
        return 0;
    }
    string command,title,line;
    int day,hour;
    EventPlanner eventPlanner;
    while(!commandFile.eof()){
        vector<string> line_vector;
        getline(commandFile,line);
        split_to_vector(line_vector,line);
        command = line_vector[0];
        if(command == "ADD"){
            if(line_vector.size()!=4){
                cout<<"Invalid arguments\n";
            }
            else{
                title = line_vector[1];
                if(is_number(line_vector[2])){
                    day = stoi(line_vector[2]);
                }
                else{
                    cout<<"Invalid day\n";
                    continue;
                }
                if(is_number(line_vector[3])){
                    hour = stoi(line_vector[3]);
                }
                else{
                    cout<<"Invalid hour\n";
                    continue;
                }
                eventPlanner.add(title,day,hour);
            }
        }
        else if(command=="Find"){
            if(line_vector.size()!=3){
                cout<<"Invalid arguments\n";
            }
            else{
                if(is_number(line_vector[1])){
                    day = stoi(line_vector[1]);
                }
                else{
                    cout<<"Invalid day\n";
                    continue;
                }
                if(is_number(line_vector[2])){
                    hour = stoi(line_vector[2]);
                }
                else{
                    cout<<"Invalid hour\n";
                    continue;
                }
                Meeting meeting = eventPlanner.find(day,hour);
                if(meeting.getTitle()=="Empty"){
                    cout<<meeting<<endl;
                }
                else{
                    cout<<meeting.getTitle()<<endl;
                }
                
            }
        }
        else if(command=="MOD"){
            if(line_vector.size()!=4){
                cout<<"Invalid arguments\n";
            }
            else{
                title = line_vector[1];
                if(is_number(line_vector[2])){
                    day = stoi(line_vector[2]);
                }
                else{
                    cout<<"Invalid day\n";
                    continue;
                }
                if(is_number(line_vector[3])){
                    hour = stoi(line_vector[3]);
                }
                else{
                    cout<<"Invalid hour\n";
                    continue;
                }
                Meeting meeting = eventPlanner.find(day,hour);
                if(meeting.getTitle()=="Empty"){
                    cout<<meeting<<endl;
                }
                else{
                    eventPlanner.modify(meeting,title);
                }
            }
        }
        else if(command=="DEL"){
            if(line_vector.size()!=3){
                cout<<"Invalid arguments\n";
            }
            else{
                if(is_number(line_vector[1])){
                    day = stoi(line_vector[1]);
                }
                else{
                    cout<<"Invalid day\n";
                    continue;
                }
                if(is_number(line_vector[2])){
                    hour = stoi(line_vector[2]);
                }
                else{
                    cout<<"Invalid hour\n";
                    continue;
                }
                Meeting meeting = eventPlanner.find(day,hour);
                if(meeting.getTitle()=="Empty"){
                    cout<<meeting<<endl;
                }
                else{
                    eventPlanner.remove(meeting);
                }
            }
        }
        else if(command=="Print"){
            if(line_vector.size()!=1){
                cout<<"Invalid arguments\n";
            }
            else{
                if(eventPlanner.isEmpty()){
                    cout<<"Empty Planner\n";
                }
                else{
                    eventPlanner.print();
                }
            }
        }
        else{
            cout<<"Invalid command\n";
        }
    }
    commandFile.close();
    return 0;
}

void split_to_vector(vector<string>& vec,string s){
    string word="";
    int i=0;
    while(s[i]!=' '&&s[i]!='\n'&&s[i]!='\t'&&s[i]!='\0'&&s[i]!='"'){
        word+=s[i++];
    }
    vec.push_back(word);
    if(s[i]=='\0'){
        return;
    }
    i++;
    word = "";
    if(s[i]==34){
        word+=s[i++];
        while(s[i]!='"'&&s[i]!='\n'&&s[i]!='\0'){
            word+=s[i++];
        }
        if(s[i]=='"'){
            word+='"';
            i++;
        }
        vec.push_back(word);
    }
    word="";
    while(i<=s.size()){
        if(s[i]==' '||s[i]=='\0'||s[i]=='\t'){
            if(word!=""&&word!=" "){
                vec.push_back(word); 
            }
            word="";
        }
        else{
            word+=s[i];
        }
        i++;
    }
}
bool is_number(string s){
    for(int i=0;i<s.size();i++){
        if(!isdigit(s[i])){
            return false;
        }
    }
    return true;
}