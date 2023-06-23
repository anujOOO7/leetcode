//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     stack<int> st;
     vector<int> vis;
     void topo(int i,vector<pair<int,int>> adj[]){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it.first]) topo(it.first,adj);
        }
        st.push(i);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        vis.resize(N,0);
        vector<int> dist(N,1e9);
        
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        //topo sort for storing the indices in stack
        for(int i=0;i<N;i++){
            if(!vis[i]){
                topo(i,adj);
            }
        }
        
        dist[0]=0;
        while(!st.empty()){
            int x=st.top();
            st.pop();
            
            for(auto it:adj[x]){
                int v=it.first,wt=it.second;
                if(dist[v]>=dist[x]+wt) dist[v]=dist[x]+wt;
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends