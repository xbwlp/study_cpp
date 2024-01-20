#include<iostream>

#include<bits/stdc++.h>

using namespace std;




int main(void){
    vector<int> nums{1,5,2,3,6,8};
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<' ';
    }

    cin.clear();
    cin.sync();
    cin.get();
}