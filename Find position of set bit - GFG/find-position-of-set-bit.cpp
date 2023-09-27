//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int n) {
        if(n&1 && n>1) return -1;
        int cnt=0,ind;
        for(int i=0;i<31;i++){
            if((1<<i)&n) cnt++,ind=i+1;
        }
        return cnt==1?ind:-1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends