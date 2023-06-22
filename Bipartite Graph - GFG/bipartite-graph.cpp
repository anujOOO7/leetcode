//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> color;
    queue<pair<int,int>> q;
    
    bool bfs(int node,vector<int> graph[]){
        q.push({node,0});
        
        while(!q.empty()){
            int x=q.front().first,c=q.front().second;
            color[x]=c;
            q.pop();
            
            for(auto i:graph[x]){
                if(color[i]==-1){
                    q.push({i,c^1});
                }
                else{
                    if(color[x]==color[i]) return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int n, vector<int>graph[]){
	    // Code here
	    color.resize(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,graph)) return false;
            }
        }
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends