#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>

using namespace std;
class Solution {
private:
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };


public:
    int romanToInt(string s) {
        int num = 0;
        for(int i = 0; i<s.length()-1; i++){
            if(symbolValues[s[i]]<symbolValues[s[i+1]]){
                num -=symbolValues[s[i]];
            }else{
                num +=symbolValues[s[i]];
            }
            
        }
        num +=symbolValues[s[s.length()-1]];
        return num;
        


    }
};
int main(void){
    Solution A;

    cout<<A.romanToInt("IIIX");
    

    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();

    return 0;

}