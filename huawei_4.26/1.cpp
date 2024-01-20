#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(void){
    int T;
    cin>>T;
    vector<int> intmap(T+1,0);
    vector<vector<int>> relyMap(T+1);
    int count = T;
    for(int i = 1;i <= T;i++){
        int N;
        cin>>N;
        intmap[i] = N;
        while(N--){
            int num;
            cin>>num;
            relyMap[num].push_back(i);
        }

    }
    vector<int> flag(T+1,0);
    int res = 0;
    while(count){
        int ff=1;
        for(int i = 1;i<=T;i++){
            if(intmap[i] == 0 && flag[i] == 0){
                flag[i]=1;
                for(int j = 0; j < relyMap[i].size();j++){
                    intmap[relyMap[i][j]]--;
                }
                count--;
                ff = 0;
            }
        }
        if(ff){
            cout<<-1;
            return 0;
        }

        res++;
    }
    cout<<res;



    cin.clear();
    cin.sync();
    cin.get();
}
    

    
