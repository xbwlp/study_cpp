#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int posit=1;
        while((s[i]==' ')&& (i<s.length()-1)){
            i++;
        }
        if(s[i]=='+'){
            i++;
        }else if (s[i]=='-')
        {
            posit = -1;
            i++;    /* code */
        }
        int start = i;
        while ((s[i]!=' ')&&(i<s.length())){

            i++;
        }
        int end = i;

        string num = s.substr(start,end);
        int result=0;
        
        for (i=0;i<num.length();i++){
            int ch = num[i]-'0';
            if(ch>=0&&ch<=9){
                if(result>INT32_MAX/10 || result==INT32_MAX/10 && ch>INT32_MAX%10){
                    return INT32_MAX;
                }else if (result<INT32_MIN/10 || result==INT32_MIN && ch<INT32_MIN%10)
                {
                    return INT32_MIN;
                }else{
                    result = result*10 + posit * ch;
                }
            }else{
                break;
            }
            
            
            
        }
        cout<<result;
        return result;

    }
};

int main(void){
    Solution A;
    A.myAtoi("-42");
    

    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();

    return 0;

}