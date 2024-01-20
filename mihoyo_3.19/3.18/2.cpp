#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(void){
    int T;
    cin>>T;
    while(T--){
        bool R = true;
        string a,b;
        cin>>a>>b;
        unordered_map<char,int> dict;
        for (int i = 0;i<a.size();i++){
            if(dict.find(a[i])==dict.end()){
                dict[a[i]] = 1;
            }else{
                dict[a[i]] += 1;
            }
        }
        for(int i = 0; i<b.size();i++){
            if(dict.find(b[i])==dict.end()){
                R = false;
                cout<<"No";
                break;
            }else{
                dict[b[i]] -= 1;
            }
        }
        if(R==false){
            continue;
        }
        int time = dict['m'];
        for(auto ans:dict){
            if(ans.first == 'm'|| ans.first =='h' || ans.first =='y'){
                if(ans.second != time){
                    R = false;
                    cout<<"No"<<endl;
                    break;
                }
            }else{
                if(ans.second != 0){
                    R = false;
                    cout<<"No"<<endl;
                    break;
                }
            }
        }
        if(R == true){
            cout<<"Yes"<<endl;
        }
    }
    
}