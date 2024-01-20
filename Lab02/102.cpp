#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
#include<algorithm>

void find_Nums(vector<int>& nums,int k,int& ans,unordered_map<int,int>& dict){
    int base = nums[k];
    for(int i = k; i<nums.size();i++){
        if(nums[i] % base == 0){
            ans++;
            int K = nums[i];
            int time = K/base;
            while(K<nums[nums.size()-1]){
                K = K*time;
                if(dict.find(K)!=dict.end()){
                    ans++;
                }
            }
            
        }
    }
}

int main(void){
    int T;
    cin>>T;
    unordered_map<int,int> dict;
    vector<int> nums(T);
    for(int i = 0; i<T;i++){
        cin>>nums[i];
        dict[nums[i]]=nums[i];

    }
    
    
    int ans = 0;
    for(int i = 0;i<T;i++){
        find_Nums(nums,i,ans,dict);
    }
    cout<<ans;
    while(1){}
    

    
}