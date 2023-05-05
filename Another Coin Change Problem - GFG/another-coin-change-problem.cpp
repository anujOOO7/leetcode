//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int dp[101][1001];
    
    bool solve(int ind, int target, int k, vector<int> &coins){
        if(k == 0)return target == 0;
        if(ind>=coins.size())return false;
        if(dp[k][target]!=-1) return dp[k][target];
        
        int op1 = false;
        if(target-coins[ind]>=0)op1 = solve(ind,target-coins[ind],k-1,coins);
        int op2 = solve(ind+1,target,k,coins);
        
        return dp[k][target] = op1|op2;
    }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        memset(dp,-1,sizeof(dp));
        return solve(0,target,K,coins);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends