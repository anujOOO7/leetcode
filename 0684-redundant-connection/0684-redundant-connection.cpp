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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> ans;
        DisjointSet ds(n);
        for(auto it:edges){
            if(ds.ultParent(it[0])!=ds.ultParent(it[1])){
                ds.unionBySize(it[0],it[1]);
            }
            else{
                ans.push_back(it[0]);
                ans.push_back(it[1]);
            }
        }
        return ans;
    }
};