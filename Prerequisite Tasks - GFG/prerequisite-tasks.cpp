//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int,int>>& p) {
	    vector<int> adj[n];
        for(auto it:p){
            adj[it.first].push_back(it.second);
        }
        
        vector<int> indegree(n,0);
	    for(int i=0;i<n;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<n;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    int cnt=0;
	    while(!q.empty()){
	        int x=q.front();
	        cnt++;
	        q.pop();
	        
	        for(auto it:adj[x]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
        if(cnt==n) return true;
        return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends