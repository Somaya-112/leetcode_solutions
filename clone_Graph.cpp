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

class Solution {
public:

    Node* dfs(Node* &cur,unordered_map<Node*,Node*> &mp)
    { 
        Node* node=new Node(cur->val);
         if(cur->neighbors.size()==0)
         return node;
        mp[cur]=node;
        for(auto neig: cur->neighbors)
        {
            if(mp.find(neig)==mp.end())
               node->neighbors.push_back(dfs(neig,mp));
               else
               {
                node->neighbors.push_back(mp[neig]);
               }  
        }
        return node;
    }

    Node* cloneGraph(Node* node) {
       
       if(node==NULL)
        return NULL;

        unordered_map<Node*,Node*> mp;
        return dfs(node,mp);
       

    }
};
