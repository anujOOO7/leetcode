//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int dp[1001][1010];
	int f(int i,int prev_ind,int n,int arr[]){
	    if(i==n) return 0;
	    
	    int &d=dp[i][prev_ind+1];
	    if(d!=-1) return d;
	    
	    int take=0;
	    if(prev_ind==-1 || arr[prev_ind]<arr[i]) take=max(take,arr[i]+f(i+1,i,n,arr));
	    int ntake=f(i+1,prev_ind,n,arr);
	    return d=max(take,ntake);
	}
	int maxSumIS(int arr[], int n)  
	{  
	   // memset(dp,-1,sizeof(dp));
	   // return f(0,-1,n,arr);
	    int ans[n]; 
        for (int i = 0; i < n; i++) ans[i] = arr[i];  
        for (int i = 0; i < n; i++)  
            for (int j = 0; j < i; j++)  
                if (arr[i] > arr[j] && ans[i] < ans[j] + arr[i])  
                    ans[i] = ans[j] + arr[i];  
    
        return *max_element(ans, ans + n);  
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends