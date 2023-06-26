//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod =1e9+7;
    int solve(int n, int r,vector<vector<int>> &dp)
    {
        if(r==1) return n;
        if(n==r) return 1;
        if(n<r)  return 0;
        if(dp[n][r]!=-1) return dp[n][r];
        int ans=(solve(n-1,r,dp)+solve(n-1,r-1,dp))%mod;
        return dp[n][r]=ans;
    }
    int nCr(int n, int r){
        vector<vector<int>> dp(n+1,vector<int>(r+1,-1));
        int ans=solve(n,r,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends