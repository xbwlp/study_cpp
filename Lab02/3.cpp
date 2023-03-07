#include<iostream>
using namespace std;


void preorder(const int *A, int i){
    if((*(A+i))==NULL){
        return;
    }
    cout<<*(A+i)<<' ';
    preorder(A,2*i+1);
    preorder(A,2*i+2);
}



int main(void){
    int A[63];
    int T;
    cin>>T;
    int i;
    while(T--){
        for(i=0;i<=63;i++)
            A[i]=0;
        i = 0;
        int N;
        cin>>N;
        while(N--){
            string n;
            cin>>n;
            if (n!="null"){
                int num=atoi(n.c_str());
                while(A[(i-1)/2]==0 && (i>1)){
                    A[i]=0;
                    i++;
                }
                A[i]=num;
                i++;
                
            }else{
                A[i] = 0;
                i++;
            }
        }
        preorder(A,0);
        cout<<endl;
    }
    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();
}