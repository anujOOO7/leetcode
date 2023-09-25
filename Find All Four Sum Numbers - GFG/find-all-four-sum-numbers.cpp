//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        set<vector<int>> s;
        for(int k=0;k<n;k++){
            for(int p=k+1;p<n;p++){
                int i=p+1,j=n-1;
                int res=arr[k]+arr[p];
                while(i<n && i<j){
                    // cout<<res<<" "<<arr[i]<<" "<<arr[j]<<endl;
                    if(res+arr[i]+arr[j]==target){
                        vector<int> temp{arr[i],arr[j],arr[k],arr[p]};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                        i++,j--;
                    }
                    else if(res+arr[i]+arr[j]>target) j--;
                    else i++;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto i:s) ans.push_back(i);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends