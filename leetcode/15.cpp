#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i<=nums.size(); i++){
            int l = i+1;
            int r = nums.size()-1;
            if(nums[i]==0){
                if (i+2>r){
                    return ans;
                }
                if(nums[i+1]==0&&nums[i+2]==0){
                    vector<int> ans0 = {0,0,0};
                    ans.push_back(ans0);
                    return ans;
                }
            }
            if(nums[i]>0)
                return ans;
            if (i>=1&&nums[i]==nums[i-1])
                continue;
            while(l<r){
                if(nums[l]+nums[r]<-nums[i]){
                    l++;
                    while(nums[l]==nums[l-1]){
                        l++;
                    }
                }else if (nums[l]+nums[r]>-nums[i])
                {
                    r--;
                    while(nums[r]==nums[r+1]){
                        r--;
                    }
                }else if (nums[l]+nums[r]==-nums[i])
                {
                    vector<int> ans0 = {nums[i],nums[l],nums[r]};
                    ans.push_back({nums[i],nums[l],nums[r]});
                    cout<<ans0[0]<<' '<<ans0[1]<<' '<<ans0[2]<<endl;
                    l++;
                    while(nums[l]==nums[l-1]){
                        l++;
                    }
                }
                
                
            }
        }
        return ans;
        
    }
};
int main(void){
    Solution A;
    vector<int> nums = {2,0,-2,-5,-5,-3,2,-4};
    A.threeSum(nums);
    

    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();

    return 0;

}
