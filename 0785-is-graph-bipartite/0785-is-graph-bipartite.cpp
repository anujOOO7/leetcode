class Solution {
public:
    vector<int> color;
    queue<pair<int,int>> q;
    
    bool bfs(int node,vector<vector<int>>& graph){
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
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=size(graph);
        color.resize(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,graph)) return false;
            }
        }
        return true;
    }
};