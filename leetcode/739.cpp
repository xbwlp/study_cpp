#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:


    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        list<pair<int,int> > fou;
        for(int i = 0; i<temperatures.size();i++){
            
            auto it = fou.rbegin();
            while(it != fou.rend()){
                //cout<<it->first;
                if(it->first < temperatures[i]){
                    ans[it->second] = i - it->second;
                    
                    it = decltype(it)(fou.erase((++it).base()));
                    
                }else{
                    break;
                }
            }
            fou.push_back(pair<int,int>{temperatures[i],i});
        }
        return ans;
    }
};

int main(void){
    Solution A;
    vector<int> temper;
    while(cin.peek()!='\n'){
        int num;
        cin>>num;
        temper.push_back(num);
    }
    vector<int> ans = A.dailyTemperatures(temper);

    cin.clear();
    cin.sync();
    cin.get();
}