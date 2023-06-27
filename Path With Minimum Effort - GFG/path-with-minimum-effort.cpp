//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<int> dx{-1,0,1,0};
        vector<int> dy{0,1,0,-1};
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        
        int ans=INT_MAX;
        dist[0][0]=0;
        while(!pq.empty()){
            auto k=pq.top();
            int d=k[0];
            int i=k[1];
            int j=k[2];
            pq.pop();
            
            if(i==m-1 && j==n-1) return d;
            
            for(int p=0;p<4;p++){
                int ni=i+dx[p];
                int nj=j+dy[p];
                
                if(ni>=0 && ni<m && nj>=0 && nj<n){
                    int nd=max(d,abs(heights[i][j]-heights[ni][nj]));
                    if(dist[ni][nj]>nd){
                        dist[ni][nj]=nd;
                        pq.push({nd,ni,nj});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends