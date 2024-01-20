#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    struct record{
        int index;
        vector<int>combine;
        int target;
        int state;
        record(int index, vector<int>combine, int target, int state):index(index),combine(combine),target(target),state(state){}
    };
    void dfs1(vector<vector<int> > &ans, vector<int>& candidates,int index, vector<int> &combine, int target){
        stack<record> s;
        int state = 0;
        while(1){
            if(target == 0){
                ans.push_back(combine);
                if(s.empty())
                    break;
                index = s.top().index;
                combine = s.top().combine;
                state = s.top().state;
                target = s.top().target;
                s.pop();
                
            }else if(state == 0){
                if(index+1< candidates.size()){
                    s.push(record(index,combine,target,1));
                    index = index+1;
                }else{
                    state =1;
                }
            }else if(state == 1){
                if(target < candidates[index]){
                    if(s.empty())
                    break;
                    index = s.top().index;
                    combine = s.top().combine;
                    state = s.top().state;
                    target = s.top().target;
                    s.pop();
                }
                if(target >= candidates[index]){
                    
                    s.push(record(index, combine, target, 2));
                    combine.push_back(candidates[index]);
                    target = target - candidates[index];
                    state = 0;
                }else{
                    state =2;
                }
            }else if(state == 2){
                if(s.empty())
                    break;
                index = s.top().index;
                combine = s.top().combine;
                state = s.top().state;
                target = s.top().target;
                s.pop();
            }
            
        }
    }




    void dfs(vector<vector<int> > &ans, vector<int>& candidates,int index, vector<int> &combine, int target){
        if(target == 0){
            ans.push_back(combine);
            return;
        }
        if(index + 1< candidates.size()){
            dfs(ans, candidates, index+1, combine, target);
        }
        if(target<candidates[index]){
            return;
        }
        if(target>=candidates[index]){
            combine.push_back(candidates[index]);
            dfs(ans,candidates,index,combine, target-candidates[index]);
            combine.pop_back();
        }
        return;
    }
    

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> combine;
        sort(candidates.begin(),candidates.end());
        dfs1(ans, candidates, 0, combine, target);
        return ans;
    }
};

int main(void){

    vector<int> nums;
    int target;
    while(cin.peek()!= '\n'){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    cin>>target;
    Solution A;
    vector<vector<int> > ans;
    
    ans = A.combinationSum(nums,target);
    for(int i = 0; i<ans.size();i++){
        for(int j = 0; j< ans[i].size();j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }

    cin.clear();
    cin.sync();
    cin.get();

}