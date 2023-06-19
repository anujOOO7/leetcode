class Solution {
public:
    //dfs traversal
    void dfs(int node,vector<int>& vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,vis,adj);
        }
    }
    
    int findCircleNum(vector<vector<int>>& a) {
        int n=a.size();
        vector<int> adj[n];
        
        //creation of adjacency list from adjacency matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        //check for connected components
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){ 
                dfs(i,vis,adj);
                ans++;
            }
        }
        return ans;
    }
};