#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int*> sta;
        int val[s.size()];
        int count= 0;
        int lens = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='('){
                count++;
                val[i] = count;
                
            }else if (s[i]==')')
            {
                count--;
                val[i] = count;
            }
            if(sta.empty()){
                if(s[i]=='(')
                    sta.push(val+i);
                continue;
            }
            
            int* ans = sta.top();
            // cout<<*ans;
            // cout<<ans;
            
            if(val[i]>*ans){
                sta.push(val+i);
            }else if(val[i] == *ans - 1){
                // cout<<&val<<val+i<<ans<<sizeof(*ans)<<(val + i)-ans<<endl;
                int len = (val + i)-ans+1;
                // cout<<len<<endl;
                if (len>lens){
                    lens = len;
                }
                
            }else if (val[i] == *ans)
            {
                continue;
            }else{
                if(sta.empty()){
                    continue;
                }
                sta.pop();
                if(sta.empty()){
                    continue;
                }
                ans = sta.top();
                int len = (val + i)-ans+1;
                // cout<<len<<endl;
                if (len>lens){
                    lens = len;
                }
            }
            
            
        }
        return lens;
        
    }
};


int main(void){

    string s;
    cin>>s;
    
    Solution A;
    cout<<A.longestValidParentheses(s);



    cin.clear();
    cin.sync();
    cin.get();
}