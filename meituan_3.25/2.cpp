#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    int n;
    cin>>n;
    vector<int> A(n,0);
    for(int i = 0; i<n;i++){
        cin>>A[i];
    }
    vector<int> ans(n,0);
    ans[0]=A[0];
    for(int i =1;i<n;i++){
        ans[i] = max(ans[i-1],A[i]);
        if(i>2){
            ans[i] = max(ans[i],ans[i-3]+A[i]);
        }
    }
    cout<<ans[n-1];
    cin.clear();
    cin.sync();
    cin.get();
    
}