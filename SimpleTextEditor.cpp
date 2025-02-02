#include <iostream>
#include <stack>
using namespace std;


int main() {
    int x;
    cin>>x;
    stack<pair<int,pair<string,string>>> s;
    string text="";
    s.push({0,{text,text}});  
    for(int i=0;i<x;i++)
    {
        int choice;
        cin>>choice;
        if(choice==1) // append
        {
            string w;
            cin>>w;
            s.push({1,{text,text+w}});
            text+=w;
        }
        else if(choice==2) // delete 
        {
            int k;
            cin>>k;
            int len = text.length();
            string temp=text;
            while(k>0 && temp.length() > 0) {
                temp.pop_back();
                k--;
            }
            s.push({2,{text,temp}});
            text=temp;
        }
        else if(choice==3) //print
        {
            int k;
            cin>>k;
            cout<<text[k-1];
        }
        else if(choice==4)// undo
        {
            pair<int,pair<string,string>> p=s.top();
            s.pop();
            int op=p.first;
            if(op==1){
                text=p.second.first;
            }
            else if(op==2){
                text=p.second.first;
            }
        }
        else {
            continue;
        }
    }
    // cout<<text<<endl;
    return 0;
}
