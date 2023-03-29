//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


void sol(vector<vector<int> > &m,int i,int j,int n,vector<vector<int>> visited,string s,vector<string>& ans){
  if(i==n-1 && j==n-1){
    ans.push_back(s);
    return;
  }

  //down
  if(i+1<n && !visited[i+1][j] && m[i+1][j]==1){
    visited[i+1][j]=1;
    sol(m,i+1,j,n,visited,s+'D',ans);
    visited[i+1][j]=0;
  }

  //left
  if(j-1>=0 && !visited[i][j-1] && m[i][j-1]==1){
    visited[i][j-1]=1;
    sol(m,i,j-1,n,visited,s+'L',ans);
    visited[i][j-1]=0;
  }

  //right
  if(j+1<n && !visited[i][j+1] && m[i][j+1]==1){
    visited[i][j+1]=1;
    sol(m,i,j+1,n,visited,s+'R',ans);
    visited[i][j+1]=0;
  }

  //up
  if(i-1>=0 && !visited[i-1][j] && m[i-1][j]==1){
    visited[i-1][j]=1;
    sol(m,i-1,j,n,visited,s+'U',ans);
    visited[i-1][j]=0;
  }
}

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        //i,j -> n-1,n-1 visited ans 
        vector<string> ans;
        vector<vector<int>> visited(n,vector<int> (n,0));
          visited[0][0]=1;
          if(m[0][0]==1) sol(m,0,0,n,visited,"",ans);
        //   sort(begin(ans),end(ans));
          return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends