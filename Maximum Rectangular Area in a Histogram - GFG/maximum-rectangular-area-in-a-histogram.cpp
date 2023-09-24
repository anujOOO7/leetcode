//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<int> pre,suf;
        vector<pair<int,int>> st;
        
        for(int i=0;i<n;i++){
            if(st.empty()) pre.push_back(-1);
            else{
                while(st.size() && st.back().first>=arr[i]) st.pop_back();
                if(st.size()) pre.push_back(st.back().second);
                else pre.push_back(-1);
            }
            st.push_back({arr[i],i});
        }
        
        st.clear();
        for(int i=n-1;i>=0;i--){
            if(st.empty()) suf.push_back(n);
            else{
                while(st.size() && st.back().first>=arr[i]) st.pop_back();
                if(st.size()) suf.push_back(st.back().second);
                else suf.push_back(n);
            }
            st.push_back({arr[i],i});
        }
        reverse(suf.begin(),suf.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            // cout<<pre[i]<<" "<<suf[i]<<endl;
            ans=max(ans,(suf[i]-pre[i]-1)*arr[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends