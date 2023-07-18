//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
     int longestPalinSubseq(string A) {
        string reverse_A(A);
        reverse(reverse_A.begin(), reverse_A.end());
        int l=A.length();
        vector<int> prev(l+1, 0);
        vector<int> curr(l+1, 0);
        for(int i=0; i<l; i++) {
            for(int j=0; j<l; j++) {
                if(A[i]==reverse_A[j]) {
                    curr[j+1]=prev[j]+1;
                }
                else {
                    curr[j+1]=max(curr[j], prev[j+1]);
                }
            }
            prev=curr;
        }
        return prev[l];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends