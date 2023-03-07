#include<iostream>
#include<cassert>

using namespace std;
int defaultsize = 50;
template <typename E>
class Queue{
    private:
        void operator = (const Queue&){}

        Queue(const Queue&){}
    public:
        Queue(){}
        virtual ~Queue(){}

        
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
        b.clear();
        
        int num=0;
        
        int pre = 0;
        int next = 0;
        while(cin>>num){
            a.enqueue(num);
            
            while(cin.peek()==' '){
                cin.get();
            }
            if(cin.peek()=='\n')
                break;
        }
        int k = a.length();
        next = a.dequeue();
        while(--k){
            pre = next;
            int val = a.frontValue();
            if((val==1)&&(k==1))
                break;
            next = a.dequeue();
            
            if(pre<=next){
                a.enqueue(pre);
            }else{
                b.push(pre);
            }
        }
        a.enqueue(next);
        int i=0;
        int pan = 1;
        while(a.length()&&pan){
            if(++i != a.dequeue()){
                cout<<"No"<<endl;
                pan = 0;
                break;
            }
        }
        while(b.length()&&pan){
            if(++i != b.pop()){
                cout<<"No"<<endl;
                pan = 0;
                break;
            }
        }
        if (pan)
            cout<<"Yes"<<endl;
    }
      

    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();
}