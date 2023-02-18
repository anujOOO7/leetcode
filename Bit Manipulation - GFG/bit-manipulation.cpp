//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        bool ans1=(num>>(i-1))&1;
        long long ans2=num|(1<<(i-1));
        long long ans3=num&(~(1<<(i-1)));
        cout<<ans1<<" "<<ans2<<" "<<ans3;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends