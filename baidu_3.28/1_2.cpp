#include<bits/stdc++.h>
using namespace std;



int main(void){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n;i++){
        cin>>a[i];
    }
    char b[n];
    cin.get();
    int B = 0;
    for(int i = 0; i < n; i++){
        b[i] = cin.get();
        if(b[i]=='B'){
            B += a[i];
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(b[i]=='B'){
            continue;
        }
        ans += a[i]*B;
    }
    cout<<ans;
 

    cin.clear();
    cin.sync();
    cin.get();
    
}