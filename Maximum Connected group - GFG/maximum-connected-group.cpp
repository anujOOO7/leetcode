//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    public:
    vector<int> parent,size;
    
    //constructor
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    
    //function to find the ultimate parent of any node
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
    }
    
    //union by size
    void unionBySize(int u,int v){
        int ult_u=find(u);
        int ult_v=find(v);
        
        if(ult_u==ult_v) return;
        if(size[ult_u]<size[ult_v]){
            size[ult_v]+=size[ult_u];
            parent[ult_u]=ult_v;
        }
        else{
            size[ult_u]+=size[ult_v];
            parent[ult_v]=ult_u;
        }
    }
};

class Solution {
bool valid(int i,int j,int n){
    return i>=0 && i<n && j>=0 && j<n;
}
public:
    vector<int> dx{-1,0,0,1};
    vector<int> dy{0,-1,1,0};
    int MaxConnection(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds((n*n));
        
        //union by size
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int p=0;p<4;p++){
                    int ni=i+dx[p];
                    int nj=j+dy[p];
                    
                    if(valid(ni,nj,n) && grid[ni][nj]==1){
                        int oldN=i*n+j;
                        int newN=ni*n+nj;
                        ds.unionBySize(oldN,newN);
                    }
                }
            }
        }
        
        //checking maxSize by converting each 0 to 1 one by one
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                set<int> s;
                for(int p=0;p<4;p++){
                    int ni=i+dx[p];
                    int nj=j+dy[p];

                    if(valid(ni,nj,n) && grid[ni][nj]==1){
                        s.insert(ds.find(ni*n+nj));
                    }
                }

                int ans=1;
                for(auto it:s){
                    ans+=ds.size[it];
                }
                res=max(res,ans);
            }
        }
        for(int i=0;i<n*n;i++) res=max(res,ds.size[i]);
        return res;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends