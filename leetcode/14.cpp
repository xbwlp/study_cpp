#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int j = 0;
        int cout = strs.size();
        for(j = 0;j<strs[0].length();j++){
            bool same=true;
            char c = strs[0][j];
            for(int i=1;i<cout;i++){
                if(c!=strs[i][j]){
                    same = false;
                    break;
                }
            }
            if(same==false){
                return ans;
            }else{
                ans.push_back(c);
            }
        }
    }
};
int main(void){
    Solution A;
    vector<string> strs = {
        {"flower"},{"flow"},{"flight"}
    };
    cout<<A.longestCommonPrefix(strs);
    

    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();

    return 0;

}