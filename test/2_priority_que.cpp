#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int x,y;
    bool operator <(Node a) const  {  return y < a.y; }
    bool operator >(Node a) const  {  return y > a.y; }
};

struct Node2
{
   int adj;
   int val;
   friend  bool operator<(const Node2 &a,const Node2 &b) { return  a.val > b.val; }
};
priority_queue<Node2>Q; 

struct Node1
{
   int adj;
   int val;
};
struct cmp
{
   bool operator()(Node a,Node b) { return  a.val > b.val; }
};
priority_queue<Node1,vector<Node1>,cmp>Q; 

int main(void){
   priority_queue<int,vector<int>,greater<int> > q;

    
}