class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    vector<vector<int>> adj;
    int find(int node)
    {
        int cur=node;
        while(cur!=parent[cur])
        {
           parent[cur]=parent[parent[cur]];
           cur=parent[cur];
        }

        return cur;
    }
    int union_(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        if(x==y)
        return 0;
        if(rank[y]>rank[x])
        swap(x,y);
       
            rank[x]+=rank[y];
            parent[y]=x;
        return 1;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
       parent=vector<int>(n,0);
       adj=vector<vector<int>> (n);
       for(int i=0;i<n;i++)
       {
        parent[i]=i;
       }
       rank=vector<int>(n,1);
       int ans=n;
        for(int i=0;i<edges.size();i++)
       {
        int x=edges[i][0];
        int y=edges[i][1];
        adj[x].push_back(y);
        adj[y].push_back(x);
       }
       for(int i=0;i<edges.size();i++)
       {
        int x=edges[i][0];
        int y=edges[i][1];
        
        ans-=union_(x,y);
       }

       return ans;



    }
};
