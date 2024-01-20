#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;
int main(void){
    string s;
    cin>>s;
    
    int start = 0;
    int end = 0;
    unordered_map<string,string> dict;
    while(start<s.size()){
        while(s[end]!='='){
            end++;
        }
        string temp1 = s.substr(start,end-start);
        start = end+1;
        end = start;
        while(s[end]!=';'){
            end++;
        }
        string temp2 = s.substr(start,end-start);
        start = end+1;
        end = start;
        dict[temp1]=temp2;

    }
    
    int q;
    cin>>q;
    while(q--){
        string ques;
        cin>>ques;
        if(dict.find(ques)==dict.end()){
            cout<<"EMPTY"<<endl;
        }
        cout<<dict[ques]<<endl;
    }
    cin.clear();
    cin.sync();
    cin.get();
    
}