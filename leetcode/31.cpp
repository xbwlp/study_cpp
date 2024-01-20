#include<iostream>
#include<bits/stdc++.h>



using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        while(nums[i]<nums[i-1]&&i>0){
            i--;
        }
        if(i == 0){
            for(int k = 0;k<nums.size()/2;k++){
                swap(nums[k],nums[nums.size()-1-k]);
            }
        }else{
            i--;
            int j = nums.size()-1;
            while(nums[i]>nums[j]){
                j--;
            }
            swap(nums[i],nums[j]);
            for(int k = i+1; k<(nums.size()+i+1)/2;k++){
                swap(nums[k],nums[nums.size()-k+i]);
            }
        }
    }
};

int main(void){
    Solution A;
    vector<int> que;
    while(cin.peek() != '\n'){
        int n;
        cin>>n;
        que.push_back(n);
    }
    A.nextPermutation(que);

    for(int i = 0; i<que.size();i++){
        cout<<que[i]<<' ';
    }
    
    cin.clear();
    cin.sync();
    cin.get();

}