//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        // Code here
        vector<int> g,l;
        int count=0;
        for(int i=0;i<n/2;i++) g.push_back(arr[i]);
        for(int i=n/2;i<n;i++) l.push_back(arr[i]);
        sort(g.begin(),g.end());
        sort(l.begin(),l.end());
        
        for(int i=0;i<l.size();i++){
            auto ind=g.end()-lower_bound(g.begin(),g.end(),l[i]*5);
            count+=ind;
        }
        return count;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends