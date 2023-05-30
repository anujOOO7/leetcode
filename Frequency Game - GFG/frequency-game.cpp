//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        map<int,int> m;
        for(int i=0;i<n;i++) m[arr[i]]++;
        
        vector<pair<int,int>> v;
        for(auto i:m){
            v.push_back({i.first,i.second});
        }
        
        sort(v.begin(),v.end(),[&](pair<int,int> &a,pair<int,int> &b){
            if(a.second==b.second) return a.first>b.first;
            return a.second<b.second;
        });
        return v[0].first;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends