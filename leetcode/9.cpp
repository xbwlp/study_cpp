#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int a = x;
        int b=0;
        while(a>=10){
            b = b*10 + a%10;
            a = a/10;
        }
        if (b>INT32_MAX/10 || b == INT32_MAX/10 && a>INT32_MAX%10){
            return false;
        }else{
            b = b*10 + a%10;
        }

        if(b==x){
            return true;
        }else{
            return false;
        }
    
    }
};

int main(void){
    Solution A;
    cout<<A.isPalindrome(-123454321);
    

    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();

    return 0;

}