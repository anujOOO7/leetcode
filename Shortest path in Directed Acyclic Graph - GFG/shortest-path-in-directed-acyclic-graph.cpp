//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<int>> adj[N];
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        vector<int> dist(N,INT_MAX);
        using pi=pair<int,int>;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({0,0});
        dist[0]=0;
        
        while(!pq.empty()){
            auto x=pq.top(); pq.pop();
            int cur_node=x.second;
            
            for(auto nbrPair:adj[cur_node]){
                int nbr=nbrPair[0];
                int cost=nbrPair[1];
                
                if(dist[nbr]>cost+dist[cur_node]){
                    dist[nbr]=cost+dist[cur_node];
                    pq.push({dist[nbr],nbr});
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
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