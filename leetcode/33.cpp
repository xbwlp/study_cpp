#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(nums[0]<=target){
            for(int i = 0;i<n;i++){
                if(nums[i]>target){
                    break;
                }
                if(nums[i]==target){
                    return i;
                }
            }
            return -1;
        }else{
            if(nums[n-1]>=target){
                for(int i = n-1; i>=0;i--){
                    if(nums[i]<target){
                        break;
                    }
                    if(nums[i]==target){
                        return i;
                    }

                }
                return -1;
            }else{
                return -1;
            }
        }
    }
};

int main(void){
    vector<int> nums;
    while(cin.peek()!= '\n'){
        int num;
        cin>>num;
        nums.push_back(num);

    }
    int target;
    cin>>target;
    Solution A;
    cout<<A.search(nums, target);
    cin.clear();
    cin.sync();
    cin.get();
}