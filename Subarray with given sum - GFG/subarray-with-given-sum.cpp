//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    using ll=long long;
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        vector<ll> pre(n+1,0);
        for(int i=0;i<n;i++) pre[i+1]=pre[i]+arr[i];
        
        int i=0;
        for(int j=0;j<n;j++){
            while(i<j && pre[j+1]-pre[i]>s) i++;
            if(pre[j+1]-pre[i]==s) return{i+1,j+1};
        }
        return {-1};
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends