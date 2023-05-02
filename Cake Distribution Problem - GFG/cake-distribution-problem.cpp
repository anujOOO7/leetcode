//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    bool check(vector<int>&s,int mid,int k){
        int sum=0;
        for(int i=0;i<s.size();i++){
            sum+=s[i];
            if(sum>=mid){
                k--;
                sum=0;
            }
        }
        if(k<0){
            return true;
        }
        return false;
    }
    int maxSweetness(vector<int>& s, int n, int k) {
    // Write your code here.
        int i=1;
        int j=0;
        for(int i=0;i<n;i++){
            j+=s[i];
        }
        int ans=INT_MIN;
        while(i<=j){
            int mid=(i+j)/2;
            if(check(s,mid,k)){
                ans=max(ans,mid);
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends