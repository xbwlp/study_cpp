#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<int> > edge;
    vector<int> visited;
    int valid = true;

public:
    void dfs(int u){
        visited[u] = 1;
        for(int v:edge[u]){
            if(visited[v]==0){
                dfs(v);
                if(!valid){
                    return;
                }
            }else if(visited[v] == 1){
                valid =false;
                return;
            }
        }
        visited[u] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        edge.resize(numCourses);
        visited.resize(numCourses);
        for (auto info:prerequisites){
            edge[info[1]].push_back(info[0]);
        }
        for(int i=0; i<numCourses;i++){
            dfs(i);
        }
        return valid;
    }
};

int main(void){
    int n;
    cin>>n;
    vector<vector<int> > pre;
    int fir,sec;
    while(cin>>fir>>sec){
        pre.push_back(vector<int>{fir,sec});
    }
    Solution A;
    A.canFinish(n, pre);
    cin.clear();
    cin.sync();
    cin.get();
}