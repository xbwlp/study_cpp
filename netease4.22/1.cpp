#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    int enemyNums(vector<vector<int> > &enemy, vector<int> &point, int radius){
        int ans;
        for(int i = 0; i < enemy.size(); i++){
            float distance;
            distance = sqrt(((float)enemy[i][0]-(float)point[0])*((float)enemy[i][0]-(float)point[0])+
                        ((float)enemy[i][1]-(float)point[1])*((float)enemy[i][1]-(float)point[1])+
                        ((float)enemy[i][2]-(float)point[2])*((float)enemy[i][2]-(float)point[2]));
            if(distance < radius){
                ans++;
            }
        }


        return ans;
    }
};

int main(void){
    int num, radius;
    cin>>num>>radius;
    vector<vector<int> > enemy(num,vector<int>(3));
    for(int i = 0; i < num; i++){
        cin>>enemy[i][0]>>enemy[i][1]>>enemy[i][2];
    }
    vector<int> point(3);
    cin>>point[0]>>point[1]>>point[2];

    Solution A;
    int ans = A.enemyNums(enemy, point, radius);
    cout<<ans;

    cin.clear();
    cin.sync();
    cin.get();
}