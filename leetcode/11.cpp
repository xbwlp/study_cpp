#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int max = 0;
        while(l<r){
            int space = 0;
            if(height[l] <= height[r]){
                space = height[l]*(r-l);
                l++;
            }else{
                space = height[r]*(r-l);
                r--;
            }
            if (space>max)
                max = space;
        }
        return max;
    }
};
int main(void){
    Solution A;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<A.maxArea(height);
    

    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();

    return 0;

}