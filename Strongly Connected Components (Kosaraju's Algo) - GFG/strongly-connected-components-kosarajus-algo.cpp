//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	stack<int> st;
    vector<int> vis;
    
    void dfs(int node,vector<vector<int>>& adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj);
            }
        }
        st.push(node);
    }
    
    void f(int node,vector<int> adjT[]){
        vis[node]=1;
        for(auto it:adjT[node]){
            if(!vis[it]){
                f(it,adjT);
            }
        }
    }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vis.assign(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj);
            }
        }
        
        vector<int> adjT[V];
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        int scc=0;
        vis.assign(V,0);
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            if(!vis[node]){
                scc++;
                f(node,adjT);
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends