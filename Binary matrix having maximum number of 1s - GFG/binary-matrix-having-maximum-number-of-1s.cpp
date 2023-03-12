//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        //code here
         vector<int>ans;
        int row=-1;
        int maxcount=INT_MIN;
        for(int i=0;i<N;i++){
            int index=lower_bound(mat[i].begin(),mat[i].end(),1)-mat[i].begin();
            int cnt=N-index;
            if(cnt>maxcount){
                maxcount=cnt;
                row=i;
            }
        }
        ans.push_back(row);
        ans.push_back(maxcount);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> arr(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        vector<int> ans = obj.findMaxRow(arr, n);
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends