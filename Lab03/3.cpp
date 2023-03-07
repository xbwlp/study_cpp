#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // 使用哈希表来存储键值对
        // 只是需要注意的是 这里的哈希表需要用到unordered_map 
        // 不能用到 map因为map会自动排序 导致这个顺序出问题
        unordered_map<char, int>mp = { { 'I',1 },{ 'V', 5 },{ 'X', 10 },{ 'L' , 50 },{ 'C' , 100 },{ 'D' , 500 },{ 'M' , 1000 } };
        int brea = 10000;
        int sum = 0;
        int fastNum = mp[s[0]];
        for (int i = 1; i < s.size(); ++ i)
        {   
            int num = mp[s[i]];
            if (num>brea){
                return 0;
            }
            
            if(fastNum<num/10){
                return 0;
            }else if(fastNum==num/2){
                return 0;
            }
            else if (fastNum < num) sum -= fastNum; // 这个就是特殊情况 需要减的
            else sum += fastNum;
            if(fastNum==1 && brea > 11){
                brea = 4;
            }else if(fastNum==100 && brea >101){
                brea = 49;
            }else if(fastNum==5 && brea>10){
                brea = 9;
            }else if(fastNum==50 && brea>100){
                brea = 99;
            }else if(fastNum==500 && brea>1000){
                brea = 999;
            }
            fastNum = num;            
        }
        sum += fastNum;
        return sum;
    }
    private:
        
};

int main(void){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int tr = 1;
        for(int i = 0;i<s.size();i++){
            if(s.size()>3){
                if((i+3)<s.size()){
                    if(s[i]==s[i+3]){
                        cout<<"WRONG"<<endl;
                        tr = 0;
                        break;
                    }
                }
            }

            
        }
        if(tr){
            Solution A;
            int ans = A.romanToInt(s);
            if(ans==0){
                cout<<"WRONG"<<endl;
            }else
                cout<<ans<<endl;
        }

    }
    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();

    
}