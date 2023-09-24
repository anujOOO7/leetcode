//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest(int arr[], int n, int target) 
    { 
        // Complete the function
        sort(arr,arr+n);
        auto it=lower_bound(arr,arr+n,target)-arr;
        if(it==0) return arr[it];
        auto it1=it-1;
        int x=abs(arr[it]-target);
        int y=abs(arr[it1]-target);
        if(min(x,y)==x) return arr[it];
        return arr[it1];
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,target;
        cin>>n>>target;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(arr,n,target)<<endl;
    }
}

// } Driver Code Ends