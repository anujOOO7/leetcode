class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> adj[n];
        for(auto it:p){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> indegree(n,0),ans;
	    for(int i=0;i<n;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<n;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    while(!q.empty()){
	        int x=q.front();
	        ans.push_back(x);
	        q.pop();
	        
	        for(auto it:adj[x]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
        reverse(begin(ans),end(ans));
        if(ans.size()==n) return ans;
        return {};
    }
};