//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int dp[1001][1001];
    int f(int i,int w,int n,int wt[],int val[]){
        if(w<0) return -1e8;
        if(i==n){
            if(w>=0) return 0;
            else return -1e8;
        }
        
        int &d=dp[i][w];
        if(d!=-1) return d;
        int take=0,ntake=0;
        take=val[i]+f(i+1,w-wt[i],n,wt,val);
        ntake=0+f(i+1,w,n,wt,val);
        return d=max(take,ntake);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp,-1,sizeof(dp));
       return f(0,W,n,wt,val);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends