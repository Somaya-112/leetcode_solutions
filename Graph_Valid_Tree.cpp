class Solution {
public:
    vector<vector<int>> adj;
    unordered_set<int> vis;
    int l;
    bool dfs(int cur,int prev)
    {
        if(vis.count(cur))
         return false;
         vis.insert(cur);
         for(auto nei:adj[cur])
         {
            if(nei==prev)
            continue;
            if(!dfs(nei,cur))
            return false;
         }

         return true;

    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
         l=n;
         if(edges.size()>n-1)
         return false;
       adj= vector<vector<int>>(n);
       
       for(int i=0;i<edges.size();i++)
       {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
       }
       if(dfs(0,-1) && (vis.size()==l))
         return true;
         else
         return false;
     
    }
};
