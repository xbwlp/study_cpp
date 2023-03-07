#include<iostream>
#include<string>
#include<stack>


using namespace std;

class Solution {
public:
    string intToRoman(int num) {

        string ans;
        pair<int, string> intRoman[]{
            {1000,"M"},
            {900,"CM"},
            {500,"D"},
            {400,"CD"},
            {100,"C"},
            {90,"XC"},
            {50,"L"},
            {40,"XL"},
            {10,"X"},
            {9,"IX"},
            {5,"V"},
            {4,"IV"},
            {1,"I"}

        };

        for(const auto &[value,symbol]:intRoman){
            while(num>=value){
                num -= value;
                ans += symbol;
            }
        }
        return ans;
    }
};
int main(void){
    Solution A;

    cout<<A.intToRoman(3999);
    

    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();

    return 0;

}