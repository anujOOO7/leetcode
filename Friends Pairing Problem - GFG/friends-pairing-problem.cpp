//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int mod=1000000007;
    using ll=long long;
    ll dp[10001];
    ll f(int n){
        if(n==1) return 1;
        if(n==2) return 2;
        
        ll &d=dp[n];
        if(d!=-1) return d;
        ll r=(f(n-1)*1%mod+((n-1)*f(n-2)%mod)%mod)%mod;
        return d=r%mod;
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        memset(dp,-1,sizeof(dp));
        return f(n);
    }
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends