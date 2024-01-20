#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int findAns(vector<vector<int> > &timeTable, int num, int end){
    int ans = 0;
    for(int j = 1; j<=end;j++){
        int missionNum = 0;
        for(int i = 0; i < num;i++){
            if(timeTable[i][0]<=j && timeTable[i][1]>=j){
                missionNum++;
            }
        }
        if(missionNum == 0){
            ans = ans+1;
            cout<<missionNum<<endl;
        }else if(missionNum == 1){
            ans = ans + 3;
            cout<<missionNum<<endl;
        }else if (missionNum >=2)
        {
            ans = ans+4;
            cout<<missionNum<<endl;
        }
        
    }
    return ans;
}

int main(void){
    int num;
    cin>>num;
    vector<vector<int> > timeTable(num,vector<int>(2));
    int end = 0;
    for(int i = 0; i<num;i++){
        cin>>timeTable[i][0]>>timeTable[i][1];
        if(timeTable[i][1]>end){
            end = timeTable[i][1];
        }

    }
    int ans = findAns(timeTable, num, end);
    cout<<ans;



    cin.clear();
    cin.sync();
    cin.get();

}