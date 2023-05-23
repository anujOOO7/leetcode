//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int n;
	    string s1,s2;
	    int dp[1001][1001];
	    int f(int i,int j){
	        if(i>=n || j>=n) return 0;
	        
	        if(dp[i][j]!=-1) return dp[i][j];
	        if(s1[i]==s2[j] && i!=j) return dp[i][j]=1+f(i+1,j+1);
	        return dp[i][j]=max(f(i+1,j),f(i,j+1));
	    }
		int LongestRepeatingSubsequence(string str){
		    s1=s2=str;
		    n=s1.length();
		    memset(dp,-1,sizeof(dp));
		    return f(0,0);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends