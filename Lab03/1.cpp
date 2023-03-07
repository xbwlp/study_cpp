#include<iostream>
using namespace std;
#include<cassert>
#include<iostream> 
#include<string>
int defaultsize=10;

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

using namespace std;

template<typename E>
class BinNode{
    public:
        virtual ~BinNode(){}

        virtual E& element() = 0;

        virtual BinNode* left() const = 0;

        virtual BinNode* right() const = 0;

        virtual void setLeft(BinNode*)= 0 ;

        virtual void setRight(BinNode*)=0;

        virtual bool isLeaf() = 0;
};

template<typename Key,typename E>
class BSTNode:public BinNode<E>{
    private:
        Key k;
        E it;
        BSTNode* lc;
        BSTNode* rc;
    public:
        BSTNode(){lc = rc = NULL;}
        BSTNode(Key K, E e, BSTNode* l=NULL, BSTNode* r = NULL){
            k = K;
            it = e;
            lc = l;
            rc = r;
        }
        ~BSTNode(){}

        E& element(){
            return it;    
        }

        void setElement(const E& e){
            it = e;
        }

        Key& key(){return k;} 

        void setKey(const Key& K){k = K;}

        inline BSTNode* left() const {return lc;}

        void setLeft(BinNode<E>* b){
            lc = (BSTNode*)b;
        }

        inline BSTNode* right() const {return rc;}

        void setRight(BinNode<E>* b){
            rc = (BSTNode*)b;
        }

        bool isLeaf(){
            return (lc == NULL) && (rc == NULL);
        }
};

template<typename key ,typename E>
class Dictionary{
    private:
    void operator =(const Dictionary&){}
    Dictionary(const Dictionary&){}
    public:
    Dictionary(){}
    virtual ~Dictionary(){}
    virtual void clear() =0;
    virtual void insert(const key& k, const E& e) =0;
    virtual E remove (const key & k) =0;
    virtual E removeAny() =0;
    virtual E find(const key & k) const =0;
    virtual int size() =0;
};


template<typename key,typename E>
class BST: public Dictionary<key ,E>{
    private:
    BSTNode<key,E>* root;
    BSTNode<key,E>* ptr;
    int nodeCount;
    //clearHelp
    void clearHelp(BSTNode<key,E> *root);
    //insertHelp
    BSTNode<key,E>* insertHelp(BSTNode<key,E> *root,
                               const key& K,
                               const E & e);
    //deleteMin
    BSTNode<key,E>* deleteMin(BSTNode<key,E> *root);
    //getMin
    BSTNode<key,E>* getMin(BSTNode<key,E> *root);
    //findHelp
    E findHelp(BSTNode<key,E>* root,const key& K) const;
    //printHelp
    void printHelp(BSTNode<key ,E>*,int level) const;
    //removeHelp
    BSTNode<key,E>* removeHelp(BSTNode<key,E>* root,const key& k);
    //traverseHelp
    void traverseHelp(BSTNode<key,E> *root){
        if(root==NULL) return;
        
        traverseHelp(root->left());
        cout<<root->element()<<" ";
        traverseHelp(root->right());
        
    }


    public:
    BST(){root=NULL; nodeCount=0;ptr=NULL;}
    ~BST() {clearHelp(root);}
    void clear(){
        clearHelp(root);
        root=NULL; nodeCount=0;
    }
    void insert(const key& k,const E& e){
        root=insertHelp(root,k,e);
        nodeCount++;
    }
    E remove(const key& k){
        E temp=findHelp(root,k);
        if(temp!=NULL){
            root=removeHelp(root,k);
            nodeCount--;
        }
        return temp;
    }
    E removeAny(){
        if(root!=NULL){
            E temp=root->element();
            root=removeHelp(root,root->key());
            nodeCount--;
            return temp;
        }
        else
        return NULL;
    }
    E find(const key& k) const{
        return findHelp(root,k);
    }

    int size(){return nodeCount;}

    void print()const {
        if (root==NULL) cout<<"The BST is empty.\n";
        else
            printHelp(root,0);
    }
    void traverse(){
        traverseHelp(root);
        cout<<endl;
    }

    BSTNode<key, E>* setChild(const key& k,const E& it){
        BSTNode<int,int>* temp = ptr;
        
        if(ptr==NULL){
            ptr = new BSTNode<key,E>(k,it,NULL,NULL);
            root = ptr;
        }else{
            ptr->setLeft(new BSTNode<key,E>(k,it,NULL,NULL));
            ptr = ptr ->left();
            nodeCount++;
        }
        return temp;
    }

    void jumpTo(BSTNode<key,E>* temp){
        ptr = temp;
    }

    void setSibling(const key& k,const E& it){
        ptr->setRight(new BSTNode<key,E>(k,it,NULL,NULL));
        ptr = ptr ->right();
        nodeCount++;
    }

    BSTNode<key, E>* findRoot(){return root;}
};


template<typename key, typename E>
E BST<key,E>::findHelp(BSTNode<key,E>* root,const key &k)const{
    if (root==NULL) return NULL;
    if(k<root->key())
        return findHelp(root->left(),k);
    else if(k> root->key())
        return findHelp(root->right(),k);
    else
        return root->element();
}
template<typename key,typename E>
BSTNode<key,E> * BST<key,E>::insertHelp(BSTNode<key,E>* root,const key& k,const E& it){
    if(root==NULL) return new BSTNode<key,E>(k,it,NULL,NULL);
    if(k<root->key())
        root->setLeft(insertHelp(root->left(),k,it));
    else
        root->setRight(insertHelp(root->right(),k,it));
    return root;
}
template<typename key,typename E>
BSTNode<key,E>* BST<key,E>::deleteMin(BSTNode<key,E>* root){
    if(root->left()==NULL)
        return root->right();
    else   
        root->setLeft(deleteMin(root->left()));
    return root;
}

template<typename key,typename E>
BSTNode<key,E>* BST<key,E>::getMin(BSTNode<key,E>* root){
    if(root->left()==NULL)
        return root;
    else 
        return getMin(root->left());
}

template<typename key,typename E>
BSTNode<key,E>* BST<key,E>::removeHelp(BSTNode<key,E>* root,const key& k){
    if(root==NULL) return NULL;
    else if(k<root->key())
        root->setLeft(removeHelp(root->left(),k));
    else if(k>root->key())
        root->setRight(removeHelp(root->right(),k));
    else{
        BSTNode<key,E>* temp=root;
        if(root->left() ==NULL){
            root=root->right();
            delete temp;
        }
        else if(root->right()==NULL){
            root=root->left();
            delete temp;
        }
        else{
            BSTNode<key,E>* temp=getMin(root->right());
            root->setElement(temp->element());
            root->setKey(temp->key());
            root->setRight(deleteMin(root->right()));
            delete temp;
        }

    }
    return root;
}

template<typename key,typename E>
void BST<key,E>::clearHelp(BSTNode<key,E>* root){
    if(root==NULL) return ;
    clearHelp(root->left());
    clearHelp(root->right());
    delete root;
}

template<typename key,typename E>
void BST<key,E>::printHelp(BSTNode<key,E>* root,int level)
const{
    if (root==NULL) return ;
    for(int i=0;i<level*4;i++)
        cout<<" ";
    cout<<root->key() << "\n";
    printHelp(root->left(),level+1);
    
    printHelp(root->right(), level+1);
}



int main(void){
    int T;
    cin>>T;
    
    
    while(T--){
        int num;
        cin>>num;
        AStack<BSTNode<int,int>*> poin;
        BST<int, int> A;
        
        string a;
        BSTNode<int,int>* ptr;
        cin>>a;
        
        int start = 0;
        int nums;
        char b = '(';
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == ',' || a[i]=='(' || a[i]==')') {
                string temp = a.substr(start, i - start);
                nums = atoi(temp.c_str());
                start = i + 1;
                if(b=='('){
                    ptr = A.setChild(nums,nums);
                    poin.push(ptr);
                }else if (b ==')')
                {
                    
                    
                    A.setSibling(nums,nums);
                    A.jumpTo(poin.pop());
                    
                }else if (b==',')
                {
                    A.setSibling(nums,nums);
                }
                
                b = a[i];
            }
            
            
            
        }
        // A.print();
        AQueue<BSTNode<int,int>*> Q;
        ptr = A.findRoot();
        cout<<ptr->element()<<' ';
        ptr = ptr->left();
        
        int P = A.size();
        while(1){
            while(ptr !=NULL){
                Q.enqueue(ptr);
                if(ptr->element()==0){
                    ptr = ptr->right();
                    continue;
                }
                cout<<ptr->element()<<' ';
                ptr = ptr->right();
            }
            if(Q.length()==0)
                break;
            ptr = Q.dequeue();
            ptr = ptr->left();
        }
        cout<<endl;
        
    }
    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();

    return 0;
}