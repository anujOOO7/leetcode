//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int n;
	int f(int i,int sum,int target,int coins[],vector<vector<int>> &dp){
	    if(sum==target) return 0;
	    if(i>=n || sum>target) return 1e6;
	    int ans=1e6;
	    
	    if(dp[i][sum]!=-1) return dp[i][sum];
	    ans=min(1+f(i,sum+coins[i],target,coins,dp),f(i+1,sum,target,coins,dp));
	    return dp[i][sum]=ans;
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    n=M;
	    vector<vector<int>> dp(n+1,vector<int>(V+1,-1));
	    return f(0,0,V,coins,dp)==1e6?-1:f(0,0,V,coins,dp);
	} 
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends