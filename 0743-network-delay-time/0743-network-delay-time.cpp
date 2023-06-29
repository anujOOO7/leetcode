class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        queue<vector<int>> q;
        dist[k]=0;
        q.push({0,k});
        
        while(!q.empty()){
            int u=q.front()[1];
            q.pop();
            
            for(auto it:adj[u]){
                int v=it.first;
                int nwt=it.second;
                
                if(dist[v]>dist[u]+nwt){
                    dist[v]=dist[u]+nwt;
                    q.push({dist[v],v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans=max(ans,dist[i]);
        return ans==INT_MAX?-1:ans;
    }
};