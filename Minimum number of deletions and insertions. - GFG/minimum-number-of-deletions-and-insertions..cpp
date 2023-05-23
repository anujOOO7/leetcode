//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int n,m;
	string s1,s2;
	int lcs[1001][1001];
	int f(int i,int j){
	    if(i==n || j==m) return 0;
	    
	    if(lcs[i][j]!=-1) return lcs[i][j];
	    if(s1[i]==s2[j]) return lcs[i][j]=1+f(i+1,j+1);
	    return lcs[i][j]=max(f(i+1,j),f(i,j+1));
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    n=str1.size(),m=str2.size();
	    s1=str1,s2=str2;
	    memset(lcs,-1,sizeof(lcs));
	    int c=f(0,0);
	    return (n-c)+(m-c);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends