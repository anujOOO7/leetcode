//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    const int mod=1003;
    int dp[201][201][2];
    int f(int i,int j,bool isTrue,string S){
        if(i>j) return 0;
        if(i==j){
            if(isTrue) return S[i]=='T';
            else return S[i]=='F';
        }
        
        int &d=dp[i][j][isTrue];
        if(d!=-1) return d;
        int ways=0;
        for(int k=i+1;k<j;k+=2){
            int lt=f(i,k-1,true,S);
            int rt=f(k+1,j,true,S);
            int lf=f(i,k-1,false,S);
            int rf=f(k+1,j,false,S);
        
            if(S[k]=='&'){
                if(isTrue) ways+=(lt*rt)%mod;
                else ways+=((lf*rt)%mod+(lf*rf)%mod+(lt*rf)%mod)%mod;
            }
            else if(S[k]=='|'){
                if(isTrue) ways+=((lt*rt)%mod+(lt*rf)%mod+(lf*rt)%mod)%mod;
                else ways+=(lf*rf)%mod;
            }
            else if(S[k]=='^'){
                if(isTrue) ways+=((lf*rt)%mod+(lt*rf)%mod)%mod;
                else ways+=((lt*rt)%mod+(lf*rf)%mod)%mod;
            }
        }
        return d=ways%mod;
    }
    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        return f(0,N-1,true,S)%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends