#include<iostream>
#include<cassert>
#include<string>

using namespace std;

int defaultSize = 100;
template <typename E> class List{
    private:
        void operator = (const List&){}
        List(const List&){}
    public:
        List() {}

        virtual ~List() {}

        virtual void clear()=0;

        virtual void insert(const E& item) = 0;

        virtual void append(const E& item) = 0;

        virtual E remove() = 0;

        virtual void moveToStart() = 0;

        virtual void moveToEnd() = 0;

        virtual void prev() = 0;

        virtual void next() = 0;

        virtual int length() const = 0;

        virtual int currPos() const = 0;

        virtual void moveToPos(int Pos) = 0;

        virtual const E& getValue() const = 0;
};

template<typename E>
class AList : public List<E> {
    private:
        int maxSize;
        int listSize;
        int curr; 
        E* listArray;
    public:
        AList(int size = defaultSize){
            maxSize = size; 
            listSize = curr = 0;
            listArray = new E[maxSize];
        }

        ~AList() { delete [] listArray; }

        void clear(){
            delete [] listArray;
            listSize = curr = 0;
            listArray = new E[maxSize];

        }

        void insert(const E& it){
            assert(listSize < maxSize);
            for (int i = listSize; i>curr; i--)
                listArray[i] = listArray[i-1];
            listArray[curr] = it;
            listSize++;
        }

        void append(const E& it){
            assert(listSize < maxSize);
            listArray[listSize++] = it;
        }

        E remove(){
            assert((curr >= 0) && (curr < listSize));
            E it = listArray[curr];
            for (int i = curr; i<listSize-1; i++)
                listArray[i] = listArray[i+1];
            listSize--;
            return it;
        }

        void moveToStart() {
            curr = 0;
        }

        void moveToEnd(){curr = listSize-1;}
        
        void prev(){
            if(curr != 0)
                curr--;
        }
        
        void next(){
            if(curr<listSize)
                curr++;
        }

        int length() const{return listSize;}

        int currPos() const{
            return curr;
        }

        void moveToPos(int pos){
            assert((pos>=0) && (pos<listSize));
            curr = pos;
        }

        const E& getValue() const {
            assert((curr >= 0) && (curr < listSize));
            return listArray[curr];
        }
};


int main(void){

    string str;
    AList<int> a;
    while(cin>>str){
        if (str == "insert"){
            int T;
            int pos;
            cin>>T>>pos;
            if (pos >= a.length()){
                while(T--){
                    int data;
                    cin>>data;
                    a.append(data);
                }
            }else{
                a.moveToPos(pos);
                while(T--)
                {
                    int data;
                    cin>>data;
                    a.insert(data);
                    a.next();
                }
                
            }
            
        }else if (str == "show")
        {
            int T = a.length();
            if(T==0){
                cout<<"NULL"<<endl;
                continue;
            }
            a.moveToStart();
            while(T--){
                cout<<a.getValue()<<" ";
                a.next();
            }
            cout<<endl;
        }else if (str == "rshow")
        {
            int T = a.length();
            if(T==0){
                cout<<"NULL"<<endl;
                continue;
            }
            a.moveToEnd();
            while(T--){
                cout<<a.getValue()<<" ";
                a.prev();
            }
            cout<<endl;
        }else if (str == "delete")
        {
            int T = a.length();
            int num;
            cin>>num;
            a.moveToStart();
            while(T--){
                if(num == a.getValue()){
                    a.remove();
                }else
                {
                    a.next();
                }
                
            }
        }else if (str=="END")
        {
            break;
        }
        

        
        
        
        
    }


    
    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();
};

