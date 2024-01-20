#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int& num, int i, int j,bool& find){
    if(i==j){
        if(num == nums[i]){
            find = 1;
            return i;
        }else{
            return 0;
        }
    }
    int ans = 0;
    int m = (i+j)/2;
    
    
    ans = binarySearch(nums,num, i, m,find);
    
    if(find){
        return ans;
    }
    ans = binarySearch(nums, num, m+1, j,find);
    if(find){
        return ans;
    }
    return -1;
    
}

int main(void){
    vector<int> nums{1,2,3,4,5,6,7,8};
    int n = nums.size();
    int num = 8;
    bool find = 0;
    cout<<binarySearch(nums, num, 1, n-1, find);

    cin.clear();
    cin.sync();
    cin.get();
}