#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reback(vector<vector<int>>& ans, vector<int>& output, int first, int len){
        if(first == len){
            ans.push_back(output);
        }
        for(int i = first;i<=len;i++){
            swap(output[first],output[i]);
            reback(ans, output, first+1,len);
            swap(output[first],output[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        reback(ans,nums,0,nums.size()-1);

        return ans;
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
    vector<vector<int>> ans = A.permute(nums);
    
    cin.clear();
    cin.sync();
    cin.get();
}