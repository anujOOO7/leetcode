class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> adj[n];
        for(auto it:p){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> indegree(n);
	    for(auto i = 0; i < n; i++) {
	        for(auto j: adj[i])
	            indegree[j]++;
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < n; i++) {
	        if(!indegree[i])
	            q.push(i);
	    }
	    
	    vector<int> ans;
	    while(!q.empty()) {
	        auto p = q.front();
	        q.pop();
	        
	        ans.push_back(p);
	        for(auto v: adj[p]) {
	            indegree[v]--;
	            if(!indegree[v])
	                q.push(v);
	        }
	    }
        reverse(begin(ans),end(ans));
        if(ans.size()==n) return ans;
        return {};
    }
};