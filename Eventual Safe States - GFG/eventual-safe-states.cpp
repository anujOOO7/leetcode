//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> vis,pathVis,mark;
    bool dfs(int node,vector<int> adj[]){
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj)) return true;
            }
            else if(pathVis[it]) return true;
        }
        mark[node]=1;
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<int> ans;
        vis.assign(n,0);
        pathVis.assign(n,0);
        mark.assign(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,adj);
        }
        for(int i=0;i<n;i++){
            if(mark[i]) ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends