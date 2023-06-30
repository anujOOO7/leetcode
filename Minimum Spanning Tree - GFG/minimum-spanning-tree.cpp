//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> parent,rank,size;
    public:
    
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    //finding ultimate parent of a given node
    int ultParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=ultParent(parent[node]);
    }
    
    //union by size
    void unionBySize(int u,int v){
        int ult_u=ultParent(u);
        int ult_v=ultParent(v);
        
        if(ult_u==ult_v) return;
        if(size[ult_u]<size[ult_v]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else{
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //__________________PRIM'S ALGORITHM_______________
        // vector<int> vis(V,0);
        // priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        // pq.push({0,0});
        
        // int sum=0;
        // while(!pq.empty()){
        //     int wt=pq.top()[0];
        //     int node=pq.top()[1];
        //     pq.pop();
            
        //     if(vis[node]) continue;
        //     vis[node]=1;
        //     sum+=wt;
        //     for(auto it:adj[node]){
        //         if(!vis[it[0]]){
        //             pq.push({it[1],it[0]});
        //         }
        //     }
        // }
        // return sum;
        
        
        //_______________KRUSKAL'S ALGO_____________________
        
        DisjointSet ds(V);
        vector<vector<int>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int node=i;
                int adjNode=it[0];
                int wt=it[1];
                
                edges.push_back({wt,node,adjNode});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        int res=0;
        for(auto it:edges){
            int wt=it[0];
            if(ds.ultParent(it[1])!=ds.ultParent(it[2])){
                ds.unionBySize(it[1],it[2]);
                res+=wt;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends