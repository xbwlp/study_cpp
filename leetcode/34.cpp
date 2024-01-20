#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int l = 0;
        int r = nums.size()-1;
        vector<int> ans(2,-1);
        bool lfind = 1;
        bool rfind = 1;
        while(l<=r&&l<nums.size()&& r>=0&&nums[l]<=target&&nums[r]>=target&&(lfind||rfind)){
            if(nums[l]==target){
                if(lfind){
                    ans[0]=l;
                    lfind = 0;
                }
                
                
                
            }
            if(nums[r]==target){
                if(rfind){
                    ans[1]=r;
                    rfind = 0;
                }
                
                

            }
            if(nums[l]<target){
                l++;
            }
            if(nums[r]>target){
                r--;
            }

        }
        return ans;
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
    vector<int> B = A.searchRange(nums, target);
    cout<<B[0]<<' '<<B[1]<<endl;
    cin.clear();
    cin.sync();
    cin.get();

}