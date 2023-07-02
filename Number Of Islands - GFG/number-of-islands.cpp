//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    public:
    vector<int> parent,size;
    
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
    }
    
    void unionBySize(int u,int v){
        int uu=find(u);
        int uv=find(v);
        if(uu==uv) return;
        if(size[uu]<size[uv]) swap(uu,uv);
        size[uu]+=size[uv];
        parent[uv]=uu;
    }
};

class Solution {
  public:
    vector<int> dx{-1,0,1,0};
    vector<int> dy{0,-1,0,1};
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        int cnt=0;
        vector<int> ans;
        
        for(auto it:operators){
            int r=it[0],c=it[1];
            if(vis[r][c]){
                ans.push_back(cnt);
                continue;
            }
            vis[r][c]=1;
            cnt++;
            
            for(int i=0;i<4;i++){
                int ni=r+dx[i];
                int nj=c+dy[i];
                
                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    if(vis[ni][nj]){
                        int a=r*m+c;
                        int adj=ni*m+nj;
                        
                        //if they are not connected
                        if(ds.find(a)!=ds.find(adj)){
                            cnt--;
                            ds.unionBySize(a,adj);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends