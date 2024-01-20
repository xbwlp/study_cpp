#include<iostream>
#include<bits/stdc++.h>


using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans;
        int n = height.size();
        int numl = 0;
        int numr = 0;
        int l_before;
        int r_before;
        int l = 0;
        int r = n-1;
        int space = 0;
        int sum= 0;
        while(l<=r){
            
            if(height[l]>numl){
                space += numl*(l-l_before);
                numl = height[l];
                
                l_before = l;
                
            }
            
            if(height[r]>numr){
                space += numr*(r_before-r);
                r_before = r;
                numr = height[r];
                
            }



            if(numl<=numr){
                sum += height[l];
                l++;
                
            }else{
                sum += height[r];
                r--;
            }
            
        }

        space+=height[r];
        space += numl*(r_before-l_before);
        
        

        ans = space - sum;

        return ans;
    }
};

int main(void){
    vector<int> nums;
    while(cin.peek() != '\n'){
        while(cin.peek()==','){
            cin.get();
        }
        int num;
        cin>>num;
        nums.push_back(num);

    }

    Solution A;
    int ans = A.trap(nums);
    cout<<ans;
    


    cin.clear();
    cin.sync();
    cin.get();
}