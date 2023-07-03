class DisjointSet{
public:
    vector<int> parent,len;
    
    DisjointSet(int n){
        parent.resize(n+1);
        len.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
    }
    
    void unite(int u,int v){
        int uu=find(u);
        int uv=find(v);
        
        if(uu==uv) return;
        if(len[uu]<len[uv]) swap(uu,uv);
        parent[uv]=uu;
        len[uu]+=len[uv];
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        DisjointSet ds(nums.size()+1);
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()) continue;
            m[nums[i]]=i;
            
            if(m.find(nums[i]+1)!=m.end()) ds.unite(i,m[nums[i]+1]);
            if(m.find(nums[i]-1)!=m.end()) ds.unite(i,m[nums[i]-1]);
        }
        
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,ds.len[i]);
        }
        return ans;
    }
};