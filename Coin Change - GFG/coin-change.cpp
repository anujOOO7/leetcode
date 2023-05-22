//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long n;
    long long dp[1001][1001];
    long long f(long long i,long long sum,long long target,int coins[]){
        if(sum==target) return 1;
        if(i>=n || sum>target) return 0;
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum]=f(i,sum+coins[i],target,coins)+f(i+1,sum,target,coins);
    }
    long long int count(int coins[], int N, int sum) {
        memset(dp,-1,sizeof(dp));
        n=N;
        return f(0,0,sum,coins);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends