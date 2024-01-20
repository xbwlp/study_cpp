#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main(void){
    int level, T;
    cin>>level>>T;
    int actPlane = level;
    int sleepPlane = 0;
    
    map<int,int> mission;
    map<int, int> sleep;
    vector<vector<int> > missionSort;
    queue<pair<int,int> > qmissionPre;
    while(T--){
        int id;
        cin>>id;
        if(id!=-1){
            int num;
            cin>>num;
            if(actPlane>=num){
                actPlane -= num;
                
                missionSort.push_back(vector<int>{id,num,1});
                mission[id] = missionSort.size()-1;
                cout<<num<<endl;
            }else{
                if(actPlane == level){
                    level = num;
                    actPlane = num;
                    actPlane -= num;
                
                    missionSort.push_back(vector<int>{id,num,1});
                    mission[id] = missionSort.size()-1;
                    cout<<num<<endl;
                }else{
                    qmissionPre.push(pair<int,int>{id,num});
                    missionSort.push_back(vector<int>{id,num,1});
                    mission[id] = missionSort.size()-1;
                    cout<<0<<endl;
                }
                
            }


        }else{
            int id_return;
            cin>>id_return;
            int back1 = mission[id_return];
            
            sleepPlane += missionSort[back1][1];
            sleep[missionSort[back1][0]] = missionSort[back1][1];
            missionSort[back1][1] = 0;
            
            for(int i = 0; i < missionSort.size(); i++){
                if(missionSort[i][1]!=0){
                    break;
                }else {
                    if(missionSort[i][2]==1){
                        actPlane += sleep[missionSort[i][0]];
                        sleepPlane -= sleep[missionSort[i][0]];
                        missionSort[i][2]=0;
                    }
                    
                }
            }
            

            // while(it<missionSort.end()){
            //     if(it->second != 0){
            //         break;
            //     }else{
            //         actPlane += sleep[it->second];
            //         sleepPlane -= sleep[it->second];
                    
            //     }
                
            // }
            if(!qmissionPre.empty()){
                auto fly = qmissionPre.front();
                if(actPlane>=fly.second){
                    actPlane -= fly.second;
                
                    missionSort.push_back(vector<int>{fly.first,fly.second,1});
                    mission[fly.first] = missionSort.size()-1;
                    cout<<fly.second<<endl;
                    qmissionPre.pop();
                    continue;
                }else{
                    if(actPlane == level){
                        level = fly.second;
                        actPlane = fly.second;
                        actPlane -= fly.second;
                
                        missionSort.push_back(vector<int>{fly.first,fly.second,1});
                        mission[fly.first] = missionSort.size()-1;
                        cout<<fly.second<<endl;
                        continue;
                    }
                    // else{
                    //     cout<<0<<endl;
                    //     continue;
                    // }
                    // cout<<0<<endl;
                    // continue;
                
                }
                // cout<<0<<endl;
                // continue;

                
                
            }
            cout<<0<<endl;
            // else{
            //     cout<<0<<endl;
            //     continue;
            // }
            // cout<<0<<endl;
            // continue;
            
            
            
        }
    }
    cin.clear();
    cin.sync();
    cin.get();
}