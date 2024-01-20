#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<math.h>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> dict;
        int ans=0;
        while(dict.find(n)==dict.end()){
            while(n>0){
                ans += pow(n%10,2);
                n = n/10;
            }
            n = ans;
            if(ans == 1)
                return true;
            ans = 0;
            dict[n] = n;
        }
        return false;    
    }
};
int main(void){
    Solution A;
    
    cout<<A.isHappy(100);
    

    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();

    return 0;

}
