//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int n;
    vector<string> ans;
    void f(int i,int j,string s,vector<vector<int>> &m,vector<vector<int>> &vis){
        if(i<0 || i>=n || j<0 || j>=n || vis[i][j] || !m[i][j]) return;
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        vis[i][j]=1;
        
        f(i-1,j,s+'U',m,vis);
        f(i+1,j,s+'D',m,vis);
        f(i,j-1,s+'L',m,vis);
        f(i,j+1,s+'R',m,vis);
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int N) {
        n=N;
        vector<vector<int>> vis(n,vector<int>(n,0));
        f(0,0,"",m,vis);
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