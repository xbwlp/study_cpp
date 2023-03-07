#include<iostream>
#include<cassert>
using namespace std;
int defaultsize = 100;

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

template <typename E>
class Link{
    public:
        E element;
        Link *next;
        Link(const E& elemval, Link *nextval = NULL){
            element = elemval;
            next = nextval;
        }
        Link(Link *nextval = NULL){
            next = nextval;
        }
};

template<typename E>
class LList : public List<E>{
    private:
        Link<E>* head;
        Link<E>* curr;
        Link<E>* tail;
        int cnt;
        void init(){
            curr = tail = head = new Link<E>;
            cnt = 0;
        }
        void removeall(){
            while(head != NULL){
                curr = head;
                head = head -> next;
                delete curr;
            }
        }
    public:
        LList(int size = defaultsize){
            init();
        }
        ~LList(){
            removeall();
        }
        void print() const;
        void clear(){
            removeall();
            init();
        }
        void insert(const E& it){
            curr->next = new Link<E>(it, curr->next);
            if (tail==curr){
                tail = curr->next;
            }
            cnt++;
        }

        void append(const E& it){
            tail = tail -> next = new Link<E>(it,NULL);
            cnt++;
        }

        E remove(){
            assert(curr->next != NULL);
            E it = curr->next->element;
            Link<E>* ltemp = curr->next;
            if (curr->next = tail)
                tail = curr;
            curr->next = curr ->next -> next;
            delete ltemp;
            cnt--;
            return it;
        }

        void moveToStart(){
            curr = head;
        }

        void moveToEnd(){
            curr = tail;
        }

        void prev(){
            if (curr == head) return;
            Link<E>*temp = head;
            while(temp->next != curr){
                temp = temp->next;
            }
            curr = temp;
        }

        void next(){
            if (curr != tail)
                curr = curr->next;
        }

        int length() const{
            return cnt;
        }

        int currPos() const{
            Link<E>*temp = head;
            int i;
            for (i = 0; curr!=temp;i++)
                temp = temp->next;
            return i;
        }

        void moveToPos(int pos){
            assert((pos>=0)&&(pos<=cnt));
            curr = head;
            for(int i =0; i<pos; i++)
                curr  = curr->next;
        }

        const E& getValue() const{
            assert(curr->next !=NULL);
            return curr->next->element;
        }

        void sortInsert(const E& it){
            curr = head;
            if (curr==tail){
                append(it);
            }else{
                while(curr->next->element<=it){
                    curr = curr -> next;
                    if (curr==tail)
                        break;
                }
                insert(it);
            }
        }
};


int main(void){
    LList<int> a;
    int R;
    int num;
    cin>>R;
    while(R--){
        while(cin>>num){
            a.sortInsert(num);
        }
    }
    int T = a.length();
            // if(T==0){
            //     cout<<"NULL"<<endl;
            //     continue;
            // }
            a.moveToStart();
            while(T--){
                cout<<a.getValue()<<" ";
                a.next();
            }
            cout<<endl;
    
    
    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();
};
