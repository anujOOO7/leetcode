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
    int ultParent(int u){
        if(u==parent[u]) return u;
        return parent[u]=ultParent(parent[u]);
    }
    
    //union by size
    void unionBySize(int u,int v){
        int ult_u=ultParent(u);
        int ult_v=ultParent(v);
        
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
public:
    int findCircleNum(vector<vector<int>>& a) {
        int n=a.size();
        vector<int> adj[n];
        
        //creation of adjacency list from adjacency matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        DisjointSet ds(n);
        //union by size
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                if(ds.ultParent(i)!=ds.ultParent(it)){
                    ds.unionBySize(i,it);
                }
            }
        }
        
        //counting for the ultimate parents i.e. no. of provinces
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i==ds.parent[i]) cnt++;
        }
        return cnt;
    }
};