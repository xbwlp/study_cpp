#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct nums{
    int num;
    int import;
    nums(int num,int import):num(num),import(import){}
    friend bool operator<(const nums &t1, const nums &t2){
        if(t1.num!=t2.num){
            return t1.num<t2.num;
        }else{
            return t1.import<t2.import;
        }
    }
};

int main(void){
    int num;
    cin>>num;
    vector<nums> pic;
    for(int i = 0; i<num;i++){
        int num,import;
        cin>>num>>import;
        pic.push_back(nums{num,import});
    }

    sort(pic.begin(),pic.end());
    // for(int i = 0; i<num;i++){

    //     pic.pop();
    // }
    
    

    cin.clear();
    cin.sync();
    cin.get();
}