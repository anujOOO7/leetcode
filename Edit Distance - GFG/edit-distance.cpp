//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int dp[101][101];
    int f(int i,int j,string s,string t){
        if(i==s.length()) return t.length()-j;
        if(j==t.length()) return s.length()-i;
        
        int &d=dp[i][j];
        if(d!=-1) return d;
        int ans=INT_MAX;
        if(s[i]==t[j]) ans=0+f(i+1,j+1,s,t);
        else{
            ans=min(ans,1+f(i+1,j,s,t));
            ans=min(ans,1+f(i,j+1,s,t));
            ans=min(ans,1+f(i+1,j+1,s,t));
        }
        return d=ans;
    }
    int editDistance(string s, string t) {
        // Code here
        memset(dp,-1,sizeof(dp));
        return f(0,0,s,t);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends