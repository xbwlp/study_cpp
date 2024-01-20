#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(void){
    
    vector<int> v1;
    for(int i=0;i<10000;i++)
	    v1.push_back(i);
    cout<<"size:"<<v1.size()<<endl;
    cout<<"capacity:"<<v1.capacity()<<endl;

    vector<int> (v1).swap(v1);
    cout<<"size:"<<v1.size()<<endl;
    cout<<"capacity:"<<v1.capacity()<<endl;
    cout<<v1[5];

    string a = "hello";
    cout<<typeid(a).name();

    cin.clear();
    cin.sync();
    cin.get();
}