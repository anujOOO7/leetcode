class Solution {
public:
    const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        using ll=long long;
        vector<ll> t(n,LONG_MAX),ways(n,0);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push({0,0});
        t[0]=0;
        ways[0]=1;
        
        while(!pq.empty()){
            ll node=pq.top().second;
            ll time=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                ll nt=it.second;
                ll nn=it.first;
                
                if(t[nn]>nt+time){
                    t[nn]=nt+time;
                    pq.push({t[nn],nn});
                    ways[nn]=ways[node];
                }
                else if(t[nn]==nt+time){ 
                    ways[nn]=(ways[nn]+ways[node])%mod;
                }    
            }
        }
        return ways[n-1]%mod;
    }
};