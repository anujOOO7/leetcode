//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int n;
    vector<vector<int>> dp;
    bool f(int i,int sum,int arr[]){
        if(sum==0) return 1;
        if(i==n || sum<0) return 0;
        
        int &d=dp[i][sum];
        if(d!=-1) return d;
        if(f(i+1,sum-arr[i],arr)|f(i+1,sum,arr)) return d=1;
        return d=0;
    }
    int equalPartition(int N, int arr[])
    {
        n=N;
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        if(sum%2) return 0;
        dp.resize(n+1,vector<int>(sum/2+1,-1));
        return f(0,sum/2,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends