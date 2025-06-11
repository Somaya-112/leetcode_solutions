class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    
    adj=vector<vector<pair<int,int>>> (n+1);
    for(int i=0;i<times.size();i++)
    {
       int u=times[i][0];
       int v=times[i][1];
       int w=times[i][2];
       adj[u].push_back({v,w});
    }
    priority_queue<pair<int,int>> pq;
    vector<int> dis(n+1,1000000000);
    vector<int> vis(n+1,0);
    dis[k]=0;
    pq.push({0,k});
  
    int t=-1;
    while(!pq.empty())
    {
       
        int v=pq.top().second;
      
        pq.pop();
       if(vis[v])
       continue;
       vis[v]=1;
        
        for(auto nei:adj[v])
        {
            
            int node=nei.first;
            int weight=nei.second;
            
            if((dis[v]+weight)<dis[node])
            {
                dis[node]=dis[v]+weight;
                //t=max(t,dis[node]);
                pq.push({-dis[node],node});
            }

        }
    }

for(int i=1;i<=n;i++)
{
    if(dis[i]==1000000000)
    return -1;
    else
    {
        t=max(t,dis[i]);
    }
}
return t;



        
    }
};
