#include<iostream>
#include<stack>
using namespace std;

int main(void){
    int T;
    cin>>T;
    while(T--){
        int num;
        cin>>num;
        int inp[num];
        int oup[num];
        for(int i = 0; i < num; i++){
            cin>>inp[i];
        }
        for(int i = 0; i < num; i++){
            cin>>oup[i];
        }
        int l = 0;
        int r = 0;
        bool ans = false;
        stack<int> A;
        
        while(l<num){
            if(A.empty() && l<num){
                A.push(inp[l]);
                l++;
            }
            
            while(l<num && A.top()!=oup[r]){
                A.push(inp[l]);
                l++;
            }
            while(r<num && !A.empty() && A.top()==oup[r]){
                A.pop();
                r++;
            }
            
            if(r == num){
                ans = true;
            }

        }

        if(ans==true){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }

    }
    cin.clear();
    cin.sync();
    cin.get();
}