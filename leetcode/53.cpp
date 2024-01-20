#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int ans[len];
        ans[0] = nums[0];
        int ans1 = ans[0];
        for(int i = 1; i < len; i++){
            ans[i] = max(ans[i-1]+nums[i], nums[i]);
            ans1 = max(ans1,ans[i]);
        }

        return ans1;
    }
};

int main(void){
    vector<int> nums;
    while(cin.peek()!='\n'){
        int num;
        cin>>num;
        nums.push_back(num);

    }

    Solution A;
    cout<<A.maxSubArray(nums);


    cin.clear();
    cin.sync();
    cin.get();
}