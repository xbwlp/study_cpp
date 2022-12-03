#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int nums[26];
    
    for (int j = 0; j<+26;j++){
        nums[j]=0;
        for (int i=0; i<s.size();i++){
            if (s[i]=='A'+j || s[i]=='a'+j){
                nums[j]++;
            }
        }
    }
    for (int j=0;j<26;j++){
        if (nums[j]!=0){
            char k = 'A'+j;
            cout<< k <<" "<<nums[j]<<endl;
        }
    }
    
    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();
}