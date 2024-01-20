#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    unordered_map<string,string> dict{
        {"2","abc"},
        {"3","def"},
        {"4","ghi"},
        {"5","jkl"},
        {"6","mno"},
        {"7","pqrs"},
        {"8","tuv"},
        {"9","wxyz"}
    };
    void dfs(vector<string>& ans,string& temp,vector<string>& inp,int i, int j ){
        if(i+1 == inp.size()){
            temp = temp + inp[i].substr(j,1);
            ans.push_back(temp);
            temp = temp.substr(0,i);
            
            return;
        }else{  
            temp = temp + inp[i].substr(j,1);
            for(int k = 0;k<inp[i+1].size();k++){
                dfs(ans,temp,inp,i+1,k);
            }
            temp = temp.substr(0,i);
            return;
        }
    };

    vector<string> letterCombinations(string digits) {
        vector<string> inp;
        for(int i = 0;i<digits.size();i++){
            inp.push_back(dict[digits.substr(i,1)]);
        }
        vector<string> ans;
        for(int l=0;l<inp[0].size();l++){
            string temp;
            dfs(ans,temp,inp,0,l);
        }
        
        return ans;
    }
};
int main(void){
    Solution A;
    string digits;
    cin>>digits;
    vector<string> ans = A.letterCombinations(digits);
    

    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();

    return 0;

}