#include <iostream>
#include<string>
using namespace std;

int main() {
    string a,c;
    char b;
    while(cin.peek()!='\n'){
        cin>>c;
        a = a+c;
    }
    cin>>b;
    int cnt = 0;
    
    for(int i = 0; i< a.size(); i++){
        if (a[i]== b){
            cnt++;
        }
        else if (b>='a'&&b<='z'&&b == a[i]+32){
            cnt++;

        }else if (b>='A'&&b<='Z'&&b == a[i]-32) {
            cnt++;
        }
         ;
        
        
    }
    cout<<cnt;
}
// 64 位输出请用 printf("%lld")