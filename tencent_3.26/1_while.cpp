#include<bits/stdc++.h>
using namespace std;

struct ListNode {
 	int val;
 	struct ListNode *next;
    ListNode(int n):val(n),next(nullptr){}
};
 

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    struct record
    {
        ListNode* head;
        int state;
        record(ListNode* head,int state):head(head),state(state){}
    };
    

    ListNode* reorderList(ListNode* head) {
        stack<record> s;
        int state = 0;
        ListNode* next_hair = head;
        while(1){
            int cnt = 0;
            ListNode *tail = head;
            ListNode *hair = head;
            while(cnt<3 && tail->next != nullptr){
                tail = tail->next;
                cnt++;
            }
            if(cnt<3){
                if(cnt<2){
                    if(s.empty()){
                        break;
                    }
                    next_hair = head;
                    head = s.top().head;
                    state = s.top().state;
                    s.pop();
                    
                }
                if(cnt == 2){
                    
                    tail->next = head;
                    head->next->next = nullptr;
                    next_hair = tail;
                    if(s.empty()) break;
                    head = s.top().head;
                    state = s.top().state;
                    s.pop();
                    
                }
            }else if(state == 0){
                s.push(record(head,1));
                head = tail->next;
                
            }else if (state == 1)
            {
                
                hair = head->next->next;
                hair->next->next = head;
                head->next->next = next_hair;
                next_hair = hair;
                if(s.empty()) break;
                head = s.top().head;
                state = s.top().state;
                s.pop();
            }
            
            
        }
        head = next_hair;
        return head;
        
    }
};

int main(void){
    int n;
    cin>>n;
    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    head = new ListNode(n);
    curr = head;
    
    while(cin>>n){
        curr->next = new ListNode(n);
        curr = curr->next;
        
    }
    Solution A;
    head = A.reorderList(head);
    curr = head;
    cout<<curr->val<<' ';
    while(curr->next!=nullptr){
        curr = curr->next;
        cout<<curr->val<<' ';
    }
    

    cin.clear();
    cin.sync();
    cin.get();

}