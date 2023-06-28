//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int> t(n,INT_MAX),ways(n,0);
        using ll=long long;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
        pq.push({0,0});
        t[0]=0;
        ways[0]=1;
        
        while(!pq.empty()){
            int node=pq.top().second;
            ll time=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                ll nt=it.second;
                int nn=it.first;
                
                if(t[nn]>nt+time){
                    t[nn]=nt+time;
                    pq.push({t[nn],nn});
                    ways[nn]=ways[node];
                }
                else if(t[nn]==nt+time){ 
                    ways[nn]=(ways[nn]+ways[node])%mod;
                }    
            }
        }
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends