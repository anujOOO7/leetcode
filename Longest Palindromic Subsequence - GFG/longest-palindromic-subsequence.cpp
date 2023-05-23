//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    string s;
    int dp[1001][1001];
    int f(int l,int r){
        if(l>r) return 0;
        if(l==r) return 1;
        
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l]==s[r]) return dp[l][r]=2+f(l+1,r-1);
        else return dp[l][r]=max(f(l+1,r),f(l,r-1));
    }
    int longestPalinSubseq(string A) {
        s=A;
        memset(dp,-1,sizeof(dp));
        return f(0,A.length()-1);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends