/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//最后都是返回一个新的node，克隆的node
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return node;
        }
        unordered_map<Node*,Node*> visited;
        queue<Node*> Q;
        visited[node] = new Node(node->val);
        Q.push(node);
        while(!Q.empty()){
            Node* n = Q.front();
            Q.pop();
            for (auto& neighbor:n->neighbors){
                if(visited.find(neighbor)==visited.end()){
                    visited[neighbor] = new Node(neighbor->val);
                    
                    Q.push(neighbor);
                }
                visited[n]->neighbors.emplace_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};