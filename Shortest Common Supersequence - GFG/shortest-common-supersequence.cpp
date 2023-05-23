//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    int n,m;
    string s1,s2;
    int lcs[101][101];
    int f(int i,int j){
        if(i==n || j==m) return 0;
        if(lcs[i][j]!=-1) return lcs[i][j];
        if(s1[i]==s2[j]) return lcs[i][j]=1+f(i+1,j+1);
        return lcs[i][j]=max(f(i+1,j),f(i,j+1));
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int N, int M)
    {
        //code here
        n=N,m=M;
        s1=X,s2=Y;
        memset(lcs,-1,sizeof(lcs));
        return n+m-f(0,0);
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends