#include <iostream>
#include <string>
using namespace std;
char to_upper(char c)
{
    if(c>=97&&c<=122){
        return c-32;
    }
    return c;
}
int strlen(char* s)
{
    int i=0;
    while(s[i]!='\0')
    {
        i++;
    }
    return i;
}
bool is_digit(char* s)
{
    int i=0;
    if(s[0]=='-')
    {
        i++;
    }
    for(;i<strlen(s);i++)
    {
        if(!(s[i]>=48&&s[i]<=57))
        {
            return false;
        }
    }
    return true;
}
int main(int argc,char** argv)
{
    string command = argv[1];
    if(command=="print"){
        if(argc<3){
            cout<<"Incorrect Number of Arguments\n";
        }
        else
        {
            for(int i=2;i<argc;i++)
            {
                if(argv[i]!=" "||argv[i]!="\t"||argv[i]!="\n")
                {
                    cout<<argv[i]<<' ';
                }
            }
            cout<<endl;
        }
    }
    else if(command=="reverse")
    {
        if(argc<3)
        {
            cout<<"Incorrect Number of Arguments\n";
        }
        else
        {
            for(int i=argc-1;i>=2;i--)
            {
                if(argv[i]!=" "||argv[i]!="\t"||argv[i]!="\n")
                {
                    cout<<argv[i]<<' ';
                }
            }
            cout<<endl;
        }
    }
    else if(command=="upper")
    {
        if(argc<3)
        {
            cout<<"Incorrect Number of Arguments\n";
        }
        else
        {
            string temp;
            for(int i=2;i<argc;i++){
                temp=argv[i];
                if(argv[i]!=" "||argv[i]!="\t"||argv[i]!="\n")
                {
                    for(int j=0;j<temp.size();j++)
                    {
                        cout<<to_upper(argv[i][j]);
                    }
                    cout<<' ';
                } 
            }
            cout<<endl;
        }
    }
    else if(command=="shuffle")
    {
        if(argc!=3)
        {
            cout<<"Incorrect Number of Arguments\n";
        }
        else
        {
            string word=argv[2];
            for(int i=0;i<word.size()/2;i++){
                swap(word[2*i],word[2*i+1]);
            }
            cout<<word<<endl;
        }
    }
    else if(command=="shuffleStatement")
    {
        if(argc<3)
        {
            cout<<"Incorrect Number of Arguments\n";
        }
        else
        {
            string words[argc-2];
            for(int i=2;i<argc;i++)
            {
                words[i-2]=argv[i];
            }
            for(int i=0;i<(argc-2)/2;i++)
            {
                swap(words[2*i],words[2*i+1]);
            }
            for(int i=0;i<argc-2;i++)
            {
                cout<<words[i]<<' ';
            }
            cout<<endl;
        }
    }
    else if(command=="delete")
    {
        if(argc<4)
        {
            cout<<"Incorrect Number of Arguments\n";
        }
        else
        {
            int operand = atoi(argv[2]);
            if(operand<1)
            {
                cout<<"Incorrect Data Type\n";
            }
            else if(operand+2>argc)
            {
            cout<<"Incorrect Number of Arguments\n";
            }
            else
            {
                for(int i=3;i<argc;i++)
                {
                    if(i!=operand+2)
                    {
                        cout<<argv[i]<<' ';
                    }
                }
                cout<<endl;
            }
        }
    }
    else if(command=="middle")
    {
        if(argc<3)
        {
            cout<<"Incorrect Number of Arguments\n";
        }
        else
        {
            if(argc%2==0)
            {
                int i=argc/2,j=argc/2+1;
                cout<<argv[i]<<' '<<argv[j]<<endl;
            }
            else
            {
                int i=argc/2+1;
                cout<<argv[i]<<endl;
            }
        }
    }
    else if(command=="add")
    {
        if(argc<3)
        {
            cout<<"Incorrect Number of Arguments\n";
        }
        else
        {
            int temp,sum=0;
            bool exit=0;
            for(int i=2;i<argc;i++)
            {
                if(!is_digit(argv[i]))
                {
                    exit=1;
                    cout<<"Incorrect Data Type\n";
                    break;
                }
                else
                {
                    temp = atoi(argv[i]);
                    sum+=temp;  
                }
            }
            if(!exit)
            {
                cout<<sum<<endl;
            }
            
        }
    }
    else if(command=="random")
    {
        if(argc<6)
        {
            cout<<"Incorrect Number of Arguments\n";
        }
        else
        {
            if(!(is_digit(argv[2])&&is_digit(argv[3])&&is_digit(argv[4])&&is_digit(argv[5])))
            {
                cout<<"Incorrect Data Type\n";
            }
            else if(atoi(argv[2])<=0||atoi(argv[3])<0||atoi(argv[4])<0||atoi(argv[5])<0)
            {
                cout<<"Incorrect Data Type\n";
            }
            else
            {
                int sequenceLength,minNumber,maxNumber,seedValue;
                sequenceLength = atoi(argv[2]);
                minNumber = atoi(argv[3]);
                maxNumber = atoi(argv[4]);
                seedValue = atoi(argv[5]);
                srand(seedValue);
                for(int i=0;i<sequenceLength;i++){
                    cout<<rand()%(maxNumber)+minNumber<<' ';
                }
                cout<<endl;
            }
        }
    }
    else
    {
        cout<<"Undefined Command\n";
    }
    return 0;
}