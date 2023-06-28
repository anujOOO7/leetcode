class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sp, int start, int end) {
        vector<pair<int,double>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],sp[i]});
            adj[edges[i][1]].push_back({edges[i][0],sp[i]});
        }
        vector<double> ans(n,0);
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        
        while(!pq.empty()){
            double p=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                double np=it.second;
                int nn=it.first;
                
                if(np*p>ans[nn]){
                    ans[nn]=np*p;
                    pq.push({np*p,nn});
                }
            }
        }
        return ans[end];
    }
};