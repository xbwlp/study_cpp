#include<iostream>
#include<vector>
using namespace std;

// 生成一个才c[n]。0到n，使得每一项和a[n]相减最小
// 若i<j且b[i]>b[j],则c[i]>c[j]

int main(void){
    int N;
    cin>>N;
    
    vector<int> A(N);
    vector<int> B(N);
    for(int i = 0; i<N;i++){
        cin>>A[i];
    }
    for(int i = 0; i<N;i++){
        cin>>B[i];
    }
    
}