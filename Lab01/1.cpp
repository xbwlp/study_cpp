#include<iostream>
#include<vector>
#include<string>
using namespace std;



int main(){
    int T;
    
    cin>>T;
    int K=T;
    string s[T];
    int X[T];
    int Y[T];
    //输入
    while(T--){
        
        cin>>s[K-T-1];
        cin>>X[K-T-1];
        cin>>Y[K-T-1];
    }
    //计算并输出
    for (int i=0;i<K;i++){
        int a = X[i];
        int n = s[i].size();
        int b = (a-1 + Y[i])%n;//位置指针，用来更新字符串删哪个

        for (int j=0;j<n-1;j++){
            s[i].erase(b,1);
            b = (b+Y[i])%s[i].size();
        }
        cout<< s[i]<<endl;




        
        
    }
    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();
}