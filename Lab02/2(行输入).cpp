#include<iostream>
#include<cassert>

using namespace std;
int defaultsize = 100;
template <typename E>
class Queue{
    private:
        void operator = (const Queue&){}

        Queue(const Queue&){}
    public:
        Queue(){}
        virtual ~Queue(){}

        virtual void clear()=0;
        
        virtual void enqueue(const E& it) = 0;

        virtual E dequeue()=0;

        virtual const E& frontValue() const=0;

        virtual int length()const = 0;
};
template<typename E>
class AQueue : public Queue<E>{
    private:
        int maxSize;
        int front;
        int rear;
        E* listArray;
    public:
        AQueue(int size = defaultsize){
            maxSize = size+1;
            rear = 0;
            front = 1;
            listArray = new E[maxSize];
        }

        ~AQueue(){delete [] listArray;}

        void clear(){
            rear = 0;
            front = 1;
        }

        void enqueue(const E& it){
            assert((rear+2)%maxSize!=front);
            rear = (rear+1) % maxSize;
            listArray[rear] = it;
        }

        E dequeue(){
            assert (length()!=0);
            E it = listArray[front];
            front = (front + 1)%maxSize;
            return it;
        }

        const E& frontValue()const{
            assert(length() != 0);
            return listArray[front];
        }
        //自己写的
        const E& rearValue()const{
            assert(length() !=0);
            return listArray[rear];
        }

        virtual int length()const{
            return ((rear+maxSize)-front+1)%maxSize;
        }
};

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
    int T;
    cin>>T;
    
    AQueue<int> a;
    AStack<int> b;
    while(T--){
        a.clear();
        int nums[100];
        int k =0;
        int num=0;
        int Qnum=0;
        int Snum=0;
        while(cin>>num){
            a.enqueue(num);
            nums[k++] = num;
            while(cin.peek()==' '){
                cin.get();
            }
            if(cin.peek()=='\n')
                break;
        }
        int len = a.length();
        for(k = 0; nums[k] == k+1;k++){}
        if (k==len){
            cout<<"Yes"<<endl;
            break;
        }
        num = a.dequeue();
        b.push(num);
        while(1){
            if(a.length()==0){
                Qnum = 0;
            }else{
                Qnum = a.rearValue();
            }
            
            if(b.length()==0){
                Snum = 0;
            }else{
                Snum = b.topValue();
            }

            if ((Qnum - Snum)==1 || (Snum - Qnum)==1){
                if(Snum==0){
                    num = a.dequeue();
                    b.push(num);
                    continue;
                }
                num = b.pop();
                a.enqueue(num);
            }else if(((Qnum - Snum)==len || (Snum - Qnum)==len)){
                break;
            }else{
                num = a.dequeue();
                b.push(num);
            }
        }
        int i = len;
        while(i--){
            int j = a.dequeue();
            if ((len-i)!=j){
                break;
            }
        }
        if((i+1)==0){
            cout<<"Yes"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        

    }

    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();
}