#include<iostream>
#include<vector>
using namespace std;

int main(void){
    int T;
    cin>>T;
    while(T--){
        int num;
        cin>>num;
        int a[10];
        int i = 0;
        int nums;
        while(cin>>nums){
            a[i]=nums;
            i++;
            while(cin.peek()==' '){
                cin.get();
            }
            if(cin.peek()=='\n'){
                break;
            }
        }
        int l = 0;
        int r = i-1;
        int pl = l + (r-l+1)/3;
        int pr = l + 2*(pl-l);

        while(1){
            if(l==r){
                pl = l;
                pr = l;
                if(num != a[pl]){
                    cout<<a[pl]<<endl;
                    break;
                }
            }
            if(r==l+1){
                pl = l;
                pr=r;
                if(num<a[pl]){
                    cout<<a[pl]<<' ';
                    break;
                }else if(num != a[pl]&&num!=a[pr]){
                    cout<<a[pl]<<' '<<a[pr]<<endl;
                    break;
                }
            }
            


            if(num<a[pl]){
                cout<<a[pl]<<' ';
                l = l;
                r = pl;
                pl = l + (r-l+1)/3;
                pr = l + 2*(pl-l);
            }else if (num == a[pl])
            {   
                cout<<a[pl]<<' ';
                break;
            }else if (num > a[pl])
            {
                cout<<a[pl]<<' ';
                if(num<a[pr]){
                    cout<<a[pr]<<' ';
                    l = pl;
                    r = pr;
                    pl = l + (r-l+1)/3;
                    pr = l + 2*(pl-l);
                }else if (num == a[pr])
                {
                    cout<<a[pr]<<' ';
                    break;
                }else if (num>a[pr])
                {
                    cout<<a[pr]<<' ';
                    l = pr;
                    r = r;
                    pl = l + (r-l+1)/3;
                    pr = l + 2*(pl-l);
                }
                
                
            }
            
            
        }
        cout<<endl;
        // cout<<a[0]<<a[1]<<a[2]<<endl;
    }
    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();

    return 0;
}