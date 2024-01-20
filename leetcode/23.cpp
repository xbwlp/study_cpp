#include<iostream>
#include<bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
struct Node{
    int val;
    ListNode* dir;
    friend bool operator<(const Node& T1, const Node& T2){
        return T1.val<T2.val;
    }
};


class Solution {
    




public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node,vector<Node>,greater<Node>> q;
        for(int i = 0 ; i<lists.size();i++){
            while(lists[i]!=nullptr){
                q.emplace(lists[i]->val,&lists+i);
                lists[i] = lists[i]->next;
            }
            
        }
        ListNode* ans;
        ListNode* curr;
        if(!q.empty()){
            ans = q.top().dir;
            curr = ans;
            q.pop();
            while(!q.empty())
            {
                curr->next = q.top().dir;
                q.pop();
            }
        }else{
            return nullptr;
        }
        
        
        

    }
};