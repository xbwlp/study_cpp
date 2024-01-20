#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
void dfs(vector<vector<char>>& grid, int i, int j, int& cnt, char color){
        if(grid[i][j] == color){
            grid[i][j] = '0';
            if(i-1>=0 && grid[i-1][j]==color) dfs(grid, i-1,j,cnt,color);
            if(j-1>=0 && grid[i][j-1]==color) dfs(grid, i,j-1,cnt,color);
            if(i+1<grid.size()&&grid[i+1][j]==color) dfs(grid,i+1,j,cnt,color);
            if(j+1<grid[0].size()&&grid[i][j+1]==color) dfs(grid,i,j+1,cnt,color);
        }
    }

int main(void){
    int n, m;
    cin>>n>>m;
    vector<vector<char> > grid(n,vector<char>(m));
    cin.get();
    for(int i = 0;i<n;i++){
        for (int j = 0; j<m; j++){
            grid[i][j] = cin.get();
            
        }
        cin.get();
    }
    int cnt = 0;
    queue<pair<int,int> > Q;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '1'){
                Q.emplace(i,j);
                cnt++;
                grid[i][j] = 0;
                while(!Q.empty()){
                    int i1 = Q.front().first;
                    int j1 = Q.front().second;
                    Q.pop();
                    
                    if(i1-1>=0&&grid[i1-1][j1]=='1'){
                        grid[i1-1][j1] = '0';
                        Q.emplace(i1-1,j1);
                    }
                    if(j1-1>=0&&grid[i1][j1-1]=='1'){
                        grid[i1][j1-1] = '0';
                        Q.emplace(i1,j1-1);
                    }
                    if(i1+1<grid.size()&&grid[i1+1][j1]=='1'){
                        grid[i1+1][j1] = '0';
                        Q.emplace(i1+1,j1);
                    }
                    if(j1+1<grid[0].size()&&grid[i1][j1+1]=='1'){
                        grid[i1][j1+1] = '0';
                        Q.emplace(i1,j1+1);
                    }
                }
                
            }
        }
    }
    cout<<cnt;
    
   

    cin.clear();
    cin.sync();
    cin.get();
}
// 2 6
// 110011
// 001100