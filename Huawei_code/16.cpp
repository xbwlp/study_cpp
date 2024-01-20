#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, m;
    cin>>N>>m;
    N = N/10;
    vector<vector<int> > val(61, vector<int>(3,0));
    vector<vector<int> > importance(61, vector<int>(3,0));
    for(int i = 0; i < m; i++){
        int v, p, q;
        cin>>v>>p>>q;
        v = v/10;
        if (q == 0){
            val[i+1][0] = v;
            importance[i+1][0] = v * p;
        }else if (val[q][1]==0) {
            val[q][1] = v;
            importance[q][1] = v * p;
        }else{
            val[q][2] = v;
            importance[q][2] = v * p;
        }
    }
    //cout<<importance[1][2];
    vector<vector<int> > ans(m+1, vector<int>(N+1,0));
    for(int i = 1; i<m+1; i++){
        for(int j = 1; j<N+1; j++){
            int v1 = val[i][0];
            int v2 = val[i][1];
            int v3 = val[i][2];
            int imp1 = importance[i][0];
            int imp2 = importance[i][1];
            int imp3 = importance[i][2];
            ans[i][j] = ans[i-1][j];
            if(j>=v1){
                ans[i][j] = max(ans[i-1][j-v1]+imp1,ans[i-1][j]);
            }
            if(j>=v1+v2)
                ans[i][j] = max(ans[i-1][j-v1-v2]+imp1+imp2,ans[i][j]);
            if(j>=v1+v3)
                ans[i][j] = max(ans[i-1][j-v1-v3]+imp1+imp3,ans[i][j]);
            if(j>=v1+v2+v3)
                ans[i][j] = max(ans[i-1][j-v1-v2-v3]+imp1+imp2+imp3,ans[i][j]);
        }
    }
    cout<<ans[m][N]*10;
    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();
}

    
