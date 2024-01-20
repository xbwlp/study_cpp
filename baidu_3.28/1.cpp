#include<bits/stdc++.h>
using namespace std;

struct B{
    int num;
    char color;
};
bool compare(B x, B y){
    return x.color<y.color;
}

int main(void){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n;i++){
        cin>>a[i];
    }
    char b[n];
    cin.get();
    for(int i = 0; i < n; i++){
        b[i] = cin.get();
    }
    B ans[n];
    for(int i = 0; i<n;i++){
        ans[i].num = a[i];
        ans[i].color = b[i];
    }
    sort(ans,ans+n,compare);
    int i;
    for(i = 0; i<n;i++){
        if(ans[i].color=='R'){
            break;
        }
    }
    int answer = 0;
    for(int j = 0;j<i;j++){
        for(int w = i;w<n;w++){
            answer += ans[j].num*ans[w].num;
        }
    }
    answer = answer % (1000000000+7);
    cout<<answer;

    cin.clear();
    cin.sync();
    cin.get();
    
}