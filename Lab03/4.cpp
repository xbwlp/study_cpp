#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main(void){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin >> s;
        int start = 0;
        int num = 0;
        vector<int> nums;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ',') {
                string temp = s.substr(start, i - start);
                nums.push_back(atoi(temp.c_str()));
                num++;
                start = i + 1;
            }
        }
        string temp = s.substr(start, s.size() - start + 1);
        nums.push_back(atoi(temp.c_str()));
        Solution A;
        vector<int> ans;
        ans = A.twoSum(nums,nums[0]);
        cout<<ans[0]<<' '<<ans[1]<<endl;
        cout<<nums[0]<<endl;
    }

    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();
}

