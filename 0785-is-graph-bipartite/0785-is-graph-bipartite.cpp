class Solution {
public:
    int n;
    vector<int> color;
    bool dfs(int node,int col,vector<vector<int>>& graph){
        color[node]=col;
        for(auto i:graph[node]){
            if(color[i]==-1){
                if(!dfs(i,!col,graph)) return false;
            }
            else if(color[i]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n=size(graph);
        color.resize(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,0,graph)) return false;
            }
        }
        return true;
    }
};