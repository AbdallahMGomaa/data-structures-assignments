#include <iostream>
#include "inord_list.h"
#include "inord_list.cpp"
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

template <class T1,class T2>
bool cmp(pair<T1, T2>& a,pair<T1, T2>& b)
{
    return a.second < b.second;
}

bool is_delimeter(char c){
    return c==' '||c==','||c=='`'||c=='.'||c=='&'||c=='['||c==']'||c=='{'||c=='}'||c=='\t'||c=='\n'||c=='\0'||c==';';
}

string to_lower(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]>=65&&s[i]<=90){
            s[i]+=32;
        }
    }
    return s;
}

void split_to_list(InOrderedList<string> &list,string s){
    string word="";
    for(int i=0;i<=s.size();i++){
        if(is_delimeter(s[i])){
            if(word!=""&&word!=" "){
                list.insert(to_lower(word)); 
            }
            word="";
        }
        else{
            word+=s[i];
        }
    }
}

void split_to_vector(vector<string> &vec,string s){
    string word="";
    for(int i=0;i<=s.size();i++){
        if(s[i]==' '||s[i]=='\0'||s[i]=='\t'){
            if(word!=""&&word!=" "){
                vec.push_back(word); 
            }
            word="";
        }
        else{
            word+=s[i];
        }
    }
    
}

void split_to_list_pair(InOrderedList<pair<string,int>> &lp,string s,string compare,int lineNumber){
    string word="";
    for(int i=0;i<=s.size();i++){
        if(is_delimeter(s[i])){
            if(word!=""&&word!=" "){
                word=to_lower(word);
                if(word.find(compare)!=string::npos){
                    lp.insert(make_pair(word,lineNumber));
                }
            }
            word="";
        }
        else{
            word+=s[i];
        }
    }
}

bool excludedWord(string s){
    return s=="a"||s=="an"||s=="the"||s=="in"||s=="on"||s=="of"||s=="and"||s=="is"||s=="are";
}

bool startsWithStr(string s1,string s2){
    if(s2.size()>s1.size()){
        return false;
    }
    for(int i=0;i<s2.size();i++){
        if(s2[i]!=s1[i]){
            return false;
        }
    }
    return true;
}

int main(int argc,char** argv){
    if(argc!=3){
        cout<<"Incorrect number of arguments\n";
    }
    else{
        string inputFileName=argv[1],commandFileName=argv[2];
        fstream inputFile,commandFile;
        InOrderedList<string> list;
        string line;
        inputFile.open(inputFileName);
        if(inputFile.fail()){
            cout << "File not found\n";
            return 0;
        }
        int charCount=0;
        while(getline(inputFile,line)){
            charCount+=line.size()+1;
            split_to_list(list,line);
        }
        // charCount--;
        inputFile.close();
        commandFile.open(commandFileName);
        if(commandFile.fail()){
            cout << "File not found\n";
            return 0;
        }
        while(getline(commandFile,line)&&line!=""){
            vector<string> words;
            split_to_vector(words,line);
            string command=words[0];
            if(command=="wordCount"){
                if(words.size()!=1){
                    cout<<"Incorrect number of arguments\n";
                }
                else{
                    cout<<list.size()<<" words\n";
                }
            }
            else if(command=="distWords"){
                if(words.size()!=1){
                    cout<<"Incorrect number of arguments\n";
                }
                else{
                    string next,current;
                    list.first(current);
                    int count=1;
                    while(list.next(next)){
                        if(next!=current){
                            count++;
                            current=next;
                        }
                    }
                    cout<<count<<" distinct words\n";
                }
            }
            else if(command=="charCount"){
                if(words.size()!=1){
                    cout<<"Incorrect number of arguments\n";
                }
                else{
                    cout<<charCount<<" characters\n";
                }
            }
            else if(command=="frequentWord"){
                if(words.size()!=1){
                    cout<<"Incorrect number of arguments\n";
                }
                else{
                    InOrderedList<string>* frequentWords=new InOrderedList<string>();
                    int maxCount=INT32_MIN,currentCount=1;
                    string current,next;
                    list.first(current);
                    while(list.next(next)){
                        if(!(excludedWord(next)&&excludedWord(next))){
                            if(next==current){
                                currentCount++;
                            }
                            else {
                                if(currentCount>maxCount){
                                    maxCount=currentCount;
                                    if(!frequentWords->isEmpty()){
                                        delete frequentWords;
                                        frequentWords=new InOrderedList<string>();
                                    }
                                    frequentWords->insert(current);
                                }
                                else if(currentCount==maxCount){
                                    frequentWords->insert(current);
                                }
                                currentCount=1;
                                current=next;
                            }
                        }
                    }
                    frequentWords->first(current);
                    cout<<"Most frequent word is: ";
                    cout<<current;
                    while(frequentWords->next(current)){
                        cout<<' '<<current;
                    }
                    cout<<endl;
                }
            }
            else if(command=="countWord"){
                if(words.size()!=2){
                    cout<<"Incorrect number of arguments\n";
                }
                else{
                    string operand=to_lower(words[1]),current;
                    list.first(current);
                    int count=0;
                    while(list.next(current)&&current!=operand){}
                    if(current==operand)count=1;
                    while(list.next(current)&&current==operand){
                        count++;
                    }
                    cout<<operand<<" is repeated "<<count<<" times\n";
                }
            }
            else if(command=="starting"){
                if(words.size()!=2){
                    cout<<"Incorrect number of arguments\n";
                }
                else{
                    string current,operand=to_lower(words[1]);
                    list.first(current);
                    
                    vector<pair<string,int>> vec;
                    if(startsWithStr(current,operand)){
                        vec.push_back(make_pair(current,1));
                    }
                    while(list.next(current)){
                        if(startsWithStr(current,operand)){
                            if(vec.size()>0&&current==vec.back().first){
                                vec.back().second++;
                            }
                            else{
                                vec.push_back(make_pair(current,1));
                            }
                        }
                    }
                    if(vec.size()>0){
                        for(auto p:vec){
                            cout<<p.first<<": "<<p.second<<"\t";
                        }
                        cout<<endl;
                    }
                    else{
                        cout<<"Word not found\n";
                    }
                }
            }
            else if(command=="containing"){
                if(words.size()!=2){
                    cout<<"Incorrect number of arguments\n";
                }
                else{
                    string current,operand=to_lower(words[1]);
                    list.first(current);
                    vector<pair<string,int>> vec;
                    if(current.find(operand)!=string::npos){
                        vec.push_back(make_pair(current,1));
                    }
                    while(list.next(current)){
                        if(current.find(operand)!=string::npos){
                            if(vec.size()>0&&current==vec.back().first){
                                vec.back().second++;
                            }
                            else{
                                vec.push_back(make_pair(current,1));
                            }
                        }
                    }
                    if(vec.size()>0){
                        for(auto p:vec){
                            cout<<p.first<<": "<<p.second<<"\t";
                        }
                        cout<<endl;
                    }
                    else{
                        cout<<"Word not found\n";
                    }
                }
            }
            else if(command=="search"){
                if(words.size()!=2){
                    cout<<"Incorrect number of arguments\n";
                }
                else{
                    int lineNumber=1;
                    string operand=to_lower(words[1]);
                    InOrderedList<pair<string,int>> listNumbered;
                    inputFile.open(inputFileName);
                    while(getline(inputFile,line)){
                        split_to_list_pair(listNumbered,line,operand,lineNumber++);
                    }
                    inputFile.close();
                    if(!listNumbered.isEmpty()){
                        pair<string,int> current,next;
                        listNumbered.first(current);
                        cout<<current.first<<":\tlines "<<current.second<<" ";
                        while(listNumbered.next(next)){
                            if(next.first==current.first&&current.second!=next.second){
                                cout<<next.second<<" ";
                            }
                            else if(current.first!=next.first){
                                cout<<endl<<next.first<<":\tlines "<<next.second<<" ";
                            }
                            current=next;
                        }
                        cout<<endl;
                    }
                    else{
                        cout<<"Word not found\n";
                    }
                }
            }
            else{
                cout<<"Undefined command\n";
            }
        }
        commandFile.close();
    }
    return 0;
}