#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void){
    int n,m;
    cin>>n>>m;
    vector<int> weight(n,0);
    vector<int> maxw(m,0);
    for(int i = 0;i<n;i++){
        int w;
        cin>>w;
        weight[i]=w*w;
    }
    int maxwei=0;
    for(int i = 0; i<m; i++){
        cin>>maxw[i];
        if(maxwei<maxw[i]){
            maxwei = maxw[i];
        }
    }
    vector<vector<int> > ans(n+1,vector<int>(maxwei+1,0));
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=maxwei;j++){
            ans[i][j]=ans[i-1][j];
            if(j>=weight[i-1]){
                ans[i][j] = max(ans[i-1][j-weight[i-1]]+1,ans[i][j]);
            }
        }
    }
    for(int i = 0;i<m;i++){
        cout<<ans[n][maxw[i]]<<' ';
    }
    cin.clear();
    cin.sync();
    cin.get();
}