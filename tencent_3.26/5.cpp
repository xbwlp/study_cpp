#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main(void){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int num = n;
    bool equ=0;
    int notcnt = 0;
    int maj = 0;
    for(int i = 0;i<n;i++){
        if(a[i]==k){
            equ = 1;
            num = n-i-1;
            equ = 1;
        }
        if(a[i]%k != 0){
            notcnt++;
        }
        if(a[i]%k == 0){
            for(int j = i;j<n;j++){
                if(a[j]-a[i] % k == 0){
                    while(a[i]!=a[j]){
                        a[i] = min(a[j] - a[i],a[i]);
                        a[j] = max(a[j] - a[i],a[i]);
                        if(a[i]==k)
                            break;
                        notcnt++;
                    }
                }
            }
        }
        
    }
    num = num-notcnt;
    

    if(equ == 0){
        cout<<0;
    }else{
        cout<<pow(2,num);
    }


    

}
    