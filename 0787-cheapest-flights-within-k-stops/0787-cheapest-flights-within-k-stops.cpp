class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> price(n,INT_MAX);
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<vector<int>> q;
        q.push({0,src,0});
        price[src]=0;
        
        while(!q.empty()){
            int stops=q.front()[0];
            int node=q.front()[1];
            int pr=q.front()[2];
            q.pop();
            
            for(auto it:adj[node]){
                int nn=it.first;
                int np=it.second;
                
                if(stops<=k && price[nn]>pr+np){
                    price[nn]=pr+np;
                    q.push({stops+1,nn,price[nn]});
                }
            }
        }
        return price[dst]==INT_MAX?-1:price[dst];
    }
};