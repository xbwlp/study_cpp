#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//给n个string
//ab
//ac
//bcc
//每行就拿一个返回有多少个不重名字符串，比如010acb和101bac

int main(void){
    int N;
    cin>>N;
    vector<vector<char> > ques(N,vector<char>);
    
    cin.get();
    for(int i = 0 ; i<N;i++){
        
        int j = 0;
        while(cin.peek()!='\n'){
            ques[i].push_back(cin.get());
        }
        
    }
    


    cin.clear();
    cin.sync();
    cin.get();
}