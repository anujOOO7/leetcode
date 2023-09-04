//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
       queue<pair<int,int>> q;
      for(int j=0;j<m;j++){
          if(mat[0][j]=='O' && vis[0][j]==0 ){
              vis[0][j]=1;
              q.push({0,j});
          }
          if(mat[n-1][j]=='O' && vis[n-1][j]==0){
               vis[n-1][j]=1;
              q.push({n-1,j});
          }
      }
     
      for(int i=0;i<n;i++){
          if(mat[i][0]=='O' && vis[i][0]==0){
               vis[i][0]=1;
              q.push({i,0});
          }
          if(mat[i][m-1]=='O' && vis[i][m-1]==0){
               vis[i][m-1]=1;
              q.push({i,m-1});
          }
      }
      int dRow[]={-1,0,1,0};
      int dCol[]={0,1,0,-1};
      while(!q.empty()){
          int row=q.front().first;
          int col=q.front().second;
          q.pop();
          for(int i=0;i<4;i++){
              int nRow=dRow[i]+row;
              int nCol=dCol[i]+col;
              if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && mat[nRow][nCol]=='O' &&   vis[nRow][nCol]==0 ){
                  q.push({nRow,nCol});
                  vis[nRow][nCol]=1;
              }
          }
          
      }
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && vis[i][j]==0){
                    mat[i][j]='X';
                }
            }
        }
      return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends