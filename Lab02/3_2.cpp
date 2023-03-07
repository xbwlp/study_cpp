#include<iostream> 

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
    BST(){root=NULL; nodeCount=0;}
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
    cout<<root->Key() << "\n";
    printHelp(root->left(),level+1);
    
    printHelp(root->right(), level+1);
}







int main(void){
    BST<int,int> t;
    int array[]={50,75,30,40,20,80,70,2,3,99,60};
    for(int i=0;i<sizeof(array)/sizeof(int);i++){
        t.insert(array[i],array[i]);
    }
    t.traverse();
    t.remove(30);
    t.traverse();
    t.insert(73,73);
    t.traverse();
    t.removeAny();
    t.traverse();

    
    cin.clear();  //用来保证窗口不关闭的，交的时候删掉
    cin.sync();
    cin.get();
}