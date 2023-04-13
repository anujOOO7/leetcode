//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> col, vector<int> rad) {
        stack<pair<int,int>> st;
        for(int i=0;i<N;i++){
            if(st.empty()) st.push({col[i],rad[i]});
            else
            {
                auto it=st.top();
                if(it.first==col[i] && it.second==rad[i]) st.pop();
                else st.push({col[i],rad[i]});
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends