class Solution {
public:
    vector<int> vis,pathVis,mark;
    
    bool dfs(int node,vector<vector<int>>& graph){
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,graph)) return true;
            }
            else if(pathVis[it]) return true;
        }
        mark[node]=1;
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> ans;
        vis.assign(n,0);
        pathVis.assign(n,0);
        mark.assign(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,graph);
        }
        for(int i=0;i<n;i++){
            if(mark[i]) ans.push_back(i);
        }
        return ans;
    }
};