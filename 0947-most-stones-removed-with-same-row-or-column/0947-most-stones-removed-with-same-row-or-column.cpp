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
public:
    int removeStones(vector<vector<int>>& stones) {
        //(total stones-connected componenets)
        int m=0,n=0;
        for(auto it:stones){
            m=max(m,it[0]);
            n=max(n,it[1]);
        }
        
        DisjointSet ds(m+n+1);
        map<int,int> stoneNodes;
        for(auto it:stones){
            int r=it[0];
            int c=it[1]+m+1;
            ds.unionBySize(r,c);
            stoneNodes[r]=1;
            stoneNodes[c]=1;
        }
        
        int cnt=0;
        for(auto [x,y]:stoneNodes){
            if(ds.find(x)==x) cnt++;
        }
        
        return stones.size()-cnt;
    }
};