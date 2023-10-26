//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[1001][1001];
    int f(int i,int j,string &s){
        if(i>j) return 0;
        
        int &d=dp[i][j];
        if(d!=-1) return d;
        int ans=INT_MAX;
        if(s[i]==s[j]) ans=min(ans,f(i+1,j-1,s));
        ans=min({ans,1+f(i+1,j,s),1+f(i,j-1,s)});
        return d=ans;
    }
    int minimumNumberOfDeletions(string S) { 
        // code here
        memset(dp,-1,sizeof(dp));
        return f(0,S.length()-1,S);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends