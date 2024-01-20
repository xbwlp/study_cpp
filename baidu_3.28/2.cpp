#include<bits/stdc++.h>
using namespace std;

int main(void){
    cin.get();
    cin.get();
    vector<int> ans;
    string s;
    cin>>s;
    for(int i =0;i<s.size();i++){
        string temp = s.substr(i,1);
        ans.push_back(atoi(temp.c_str()));
    }
    vector<int>::iterator it = ans.begin();
    int i = 0;
    while(i+1<ans.size()){
        if(ans[i]<ans[i+1]){
            ans.erase(it+i);
            if(i>0){
                i--;
            }
        }else{
            i++;
        }
    }
    cout<<"0.";
    for(int j=0;j<ans.size();j++){
        cout<<ans[j];
    }

    cin.clear();
    cin.sync();
    cin.get();
}