class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n],adjRev[n];
        
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        vector<int> indegree(n,0),ans;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int c=q.front();
            ans.push_back(c);
            q.pop();
            
            for(auto it:adjRev[c]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};