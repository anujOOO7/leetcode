//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node,vector<int> &vis,vector<int> a[]){
        vis[node]=1;
        
        for(auto it:a[node]){
            if(!vis[it]) dfs(it,vis,a);
        }
    }
    int numProvinces(vector<vector<int>> adj, int n) {
        // code here
        vector<int> a[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]==1 && i!=j){
                    a[i].push_back(j);
                    a[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,a);
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends