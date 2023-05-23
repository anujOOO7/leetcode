//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int n,m;
    string s1,s2;
    int f(int i,int j,int count)
    {
        if(i==n || j==m) return count;
        if(s1[i]==s2[j]) count=max(count,f(i+1,j+1,count+1));
        else count=max(count,max(f(i+1,j,count),f(i,j+1,count)));
        return count;
    }
    int longestCommonSubstr (string S1, string S2, int N, int M)
    {
        s1=S1,s2=S2;
        n=N,m=M;
        // return f(0,0,0);
        int dp[n+1][m+1],result=0;
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0) dp[i][j]=0;
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    result=max(result,dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends