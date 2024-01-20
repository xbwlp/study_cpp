#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct ListNode{
    int id;
    ListNode* next;
    ListNode(int id):id(id),next(nullptr){}
    ListNode(int id, ListNode* next):id(id),next(next){}
};


int main(void){
    int start,end;
    cin>>start>>end;
    int T;
    cin>>T;
    ListNode* head;
    ListNode* curr;
    ListNode* hair;
    hair = new ListNode(0);
    head = new ListNode(start);
    curr = head;
    hair->next = head;
    int length = 1;
    for(int i = start+1;i<=end;i++){
        curr->next = new ListNode(i);
        curr = curr->next;
        length++;
    }
    while(T--){
        int n,x;
        cin>>n>>x;
        if(n==1){
            if(x>=length){
                continue;
            }
            while(x--){
                if(head!= nullptr){
                    head = head->next;
                    length--;
                    
                }
                hair->next = head;
            }
            
        }else if (n==2)
        {
            if(x>end||x<start){
                continue;
            }
            curr = head;
            if(head->id == x){
                head = head->next;
                hair->next = head;
                length--;
                continue;
                
            }
            
            while(curr->next!= nullptr && curr->next->id != x){
                curr = curr->next;
            }
            if(curr->next == nullptr){
                continue;
            }
            else if(curr->next->next!=nullptr){
                curr->next = curr->next->next;
                length--;
            }else if(curr->next!=nullptr){
                curr->next = nullptr;
                length--;
            }
            
            


            
        }else if (n==3)
        {   
            if(x>end||x<start){
                continue;
            }
            curr = hair;
            bool find = 0;
            while(curr->next!=nullptr){
                curr = curr->next;
                if(curr->id == x){
                    find = 1;
                    break;
                }
            }
            if(find){
                continue;
            }
            curr->next = new ListNode(x);
            length++;
        }
        
    }
    cout<<hair->next->id;
    cin.clear();
    cin.sync();
    cin.get();
    
    
    
    
    
}