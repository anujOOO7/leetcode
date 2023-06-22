class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> adj[n];
        for(auto it:p){
            adj[it[0]].push_back(it[1]);
        }
        
        //toppo sort method to find if a graph contains a cycle or not
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
	    
        int cnt=0;
	    while(!q.empty()) {
	        auto p = q.front();
	        q.pop();
	        
	        cnt++;
	        for(auto v: adj[p]) {
	            indegree[v]--;
	            if(!indegree[v])
	                q.push(v);
	        }
	    }
        if(cnt==n) return true;
        return false;
    }
};