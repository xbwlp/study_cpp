#include <iostream>
#include<string>
using namespace std;

int main() {
    string a;
    char b;
    
    cin >> a >> b;
    int cnt = 0;
    
    for(int i = 0; i< a.size(); i++){

        cout<<(int)a[i];
        if (a[i]== b || a[i]== b-32 || a[i]== b+32)
            {
                cnt++;
                
            }
        
    }
    cout<<cnt;

    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();
}
// 64 位输出请用 printf("%lld")