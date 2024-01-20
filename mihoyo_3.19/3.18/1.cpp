#include<iostream>
#include<unordered_map>
#include<vector>
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
    for(int i = 0;i<grid.size();i++){
        for(int j = 0;j<grid[0].size();j++){
            if(grid[i][j]=='r'){
                cnt++;
                dfs(grid,i,j,cnt,'r');
            }
        }
    }
    for(int i = 0;i<grid.size();i++){
        for(int j = 0;j<grid[0].size();j++){
            if(grid[i][j]=='g'){
                cnt++;
                dfs(grid,i,j,cnt,'g');
            }
        }
    }
    for(int i = 0;i<grid.size();i++){
        for(int j = 0;j<grid[0].size();j++){
            if(grid[i][j]=='b'){
                cnt++;
                dfs(grid,i,j,cnt,'b');
            }
        }
    }
    cout<<cnt;
    cin.clear();
    cin.sync();
    cin.get();
}
// 2 6
// rrggbb
// ggbbrr