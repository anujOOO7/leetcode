//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans(2,-1);
        
        if(n==0)
            return ans;
        
        if(lower_bound(arr,arr+n,x)!=arr+n && arr[lower_bound(arr,arr+n,x)-arr]==x){
            ans[0]=lower_bound(arr,arr+n,x)-arr;
            for(int i=ans[0];i<n;i++){
                if(arr[i]==x)
                    ans[1]=i;
            }
        }
        else
            return {-1,-1};
        return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends