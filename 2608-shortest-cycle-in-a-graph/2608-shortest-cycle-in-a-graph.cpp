class Solution {
public:
    int bfs(int i,vector<vector<int>>& adj){
        queue<int> q;
        vector<int> dist(adj.size(),INT_MAX);
        dist[i]=0;
        q.push(i);
        
        int mn=INT_MAX;
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            
            for(auto next:adj[cur]){
                if(dist[next]==INT_MAX){
                    dist[next]=dist[cur]+1;
                    q.push(next);
                }
                //condition to identify cycle 
                else if(dist[cur]<=dist[next]){
                    mn=min(mn,dist[cur]+dist[next]+1);
                }
            }
        }
        return mn==INT_MAX?-1:mn;
    }
    
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int cycleLen=bfs(i,adj);
            if(cycleLen<0) continue;
            ans=min(ans,cycleLen);
        }
        return ans==INT_MAX?-1:ans;
    }
};