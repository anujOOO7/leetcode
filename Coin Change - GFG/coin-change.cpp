//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    using ll=long long;
    ll dp[1001][1001];
    ll f(int i,int n,int sum,int coins[]){
        if(sum<0) return 0;
        if(i==n){
            if(sum==0){
                return 1;
            }
            else return 0;
        }
        
        ll &d=dp[i][sum];
        if(d!=-1) return d;
        ll ans=f(i,n,sum-coins[i],coins)+f(i+1,n,sum,coins);
        return d=ans;
    }
    long long int count(int coins[], int N, int sum) {
        memset(dp,-1,sizeof(dp));
        return f(0,N,sum,coins);
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