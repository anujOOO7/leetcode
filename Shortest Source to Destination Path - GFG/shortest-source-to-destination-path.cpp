//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // int x,y,n,m;
    // int dp[251][251];
    vector<vector<int>> moves{{-1,0},{1,0},{0,-1},{0,1}};
    // int f(int i,int j,vector<vector<int>> &A,vector<vector<int>> &vis){
    //     if(i==x && j==y) return 0;
    //     if(i<0 || i>=n || j<0 || j>=m || !A[i][j] || vis[i][j]) return 1e8;
        
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int ans=INT_MAX;
    //     for(int k=0;k<4;k++){
    //         int ni=i+moves[k][0];
    //         int nj=j+moves[k][1];
            
    //         vis[ni][nj]=1;
    //         if(A[ni][nj]) ans=min(ans,1+f(ni,nj,A,vis));
    //         vis[ni][nj]=0;
    //     }
    //     return dp[i][j]=ans;
    //     // return ans;
    // }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(!A[0][0] && X!=0 && Y!=0) return -1;
        
        queue<vector<int>> q;
        q.push({0,0,0});
        
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int i=node[0],j=node[1],dist=node[2];
                
            if(i==X && j==Y) return dist;
            for(int k=0;k<4;k++){
                int ni=i+moves[k][0];
                int nj=j+moves[k][1];
                
                if(ni>=0 && ni<N && nj>=0 && nj<M && A[ni][nj]){
                    A[ni][nj]=0;
                    q.push({ni,nj,dist+1});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends