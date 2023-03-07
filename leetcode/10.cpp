#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        int m = s.size();
        int n = p.size();
        int f[m+1][n+1];
        auto match = [&](int i,int j){
            if(i==0){
                return false;
            }else if (p[j-1] == '.' || s[i-1]==p[j-1]){
                return true;
            }else{
                return false;
            }
        };

        
        
        f[0][0]=1;
        for(int i=0;i<m+1;i++){
            if(i!=0){
                f[i][0]=0;
            }
            for (int j=1;j<n+1;j++){
                f[i][j]=0;
                if(match(i,j)){
                    f[i][j] |= f[i-1][j-1];
                    
                }
                if(p[j-1]=='*'){
                    f[i][j] |= f[i][j-2];
                    if(match(i,j-1)){
                        f[i][j] |=f[i-1][j];
                    }
                }else if(!match(i,j)){
                    f[i][j] = 0;
                }
                cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
            }
        }
        
        return f[m][n];

    }
};
int main(void){
    Solution A;
    cout<<A.isMatch("aaa","ab*a*c*a");
    

    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();

    return 0;

}