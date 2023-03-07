#include<iostream>
#include<cassert>
using namespace std;

int defaultsize = 100;
template <typename E>class Stack{
    private:
        void operator = (const Stack&){}
        Stack(const Stack&){}
    public:
        Stack(){}
        virtual ~Stack(){}
        virtual void clear()=0;
        virtual void push(const E& it)=0;
        virtual E pop()=0;
        virtual const E& topValue() const = 0;
        virtual int length() const = 0;
};

template<typename E>
class AStack : public Stack<E>{
    private:
        int maxSize;
        int top;
        E *listArray;
    public:
        AStack(int size = defaultsize){
            maxSize = size;
            top = 0;
            listArray = new E[size];
        }

        ~AStack(){
            delete[] listArray;
        }

        void clear(){
            top = 0;
        }

        void push(const E& it){
            assert(top!=maxSize);
            listArray[top++] = it;
        }

        E pop(){
            assert(top!=0);
            return listArray[--top];
        }

        const E& topValue() const{
            assert(top!=0);
            return listArray[top-1];
        }
        int length()const{
            return top;
        }
};

int main(void){
    AStack<int> a;
    int T;
    cin>>T;
    while(T--){
        a.clear();
        char inp;
        int i = 0;
        int num = 0;
        int out = 0;
        while(cin>>inp){
            
            num++;
            if(inp == '('){
                a.push(num);
            }else if (inp == ')')
            {
                i = a.pop();
                if(out<num-i+1)
                    out = num - i + 1;
            }
            if(cin.peek()=='\n')
                break;
        }
        cout<<out<<endl;
    }
    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();
}