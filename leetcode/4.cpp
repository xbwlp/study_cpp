#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        if(nums1.size()<nums2.size()){
            swap(nums1,nums2);
        }
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1==0){
            return NULL;
        }
        if(n2==0){
            if((n1+n2)%2==0){
                return ((double)nums1[n1/2-1]+(double)nums1[n1/2])/2;
            }else{
                return nums1[n1/2];
            }
        }
        if((n1+n2)%2==0){
            int m = (n1+n2)/2;
            for(int i = 0;i<n2;i++){
                if(nums2[i]>=nums1[m-i-1]){
                    if(i<1){
                        if(n1 == n2){
                            ans = ((double)nums2[i]+(double)nums1[m-i-1])/2;
                            return ans;
                        }else{
                            ans = ((double)min(nums2[i],nums1[m-i])+(double)nums1[m-i-1])/2;
                            return ans;
                        }
                        
                    }
                    ans = (double)(max(nums2[i-1],nums1[m-i-1])+(double)min(nums2[i],nums1[m-i]))/2;
                    return ans;
                }
                
                
            }if(n1>n2){
                ans = ((double)max(nums1[n1-n2-2],nums2[n2-1])+(double)nums1[n1-n2-1])/2;
            }
            else{
                ans = ((double)nums1[0]+(double)nums2[n2-1])/2;
            }
            
        }else{
            int m = (n1+n2)/2;
            for(int i = 0;i<n2;i++){
                if(nums2[i]>=nums1[m-i]){
                    if(i<1){
                        ans = nums1[m-i];
                        return ans;
                    }
                    ans = max(nums1[m-i],nums2[i-1]);
                    return ans;
                }
            }
            ans = max(nums1[m-n2],nums2[n2-1]);

        }
        return ans;
    }
};


int main(void){
    vector<int> nums1;
    vector<int> nums2;
    while(cin.peek()!='\n'){
        int n;
        cin>>n;
        nums1.push_back(n);
        
    }
    cin.get();
    while(cin.peek()!='\n'){
        int n;
        cin>>n;
        nums2.push_back(n);
        
    }
    cin.get();
    Solution A;
    double ans = A.findMedianSortedArrays(nums1,nums2);
    cout<<ans;


    cin.clear();
    cin.sync();
    cin.get();

}