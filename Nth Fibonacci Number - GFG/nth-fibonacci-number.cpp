//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    using ll=long long;
    const int mod=1000000007;
    int nthFibonacci(int n){
        ll a=0,b=1;
        if(n<2) return n-1;
        n-=1;
        while(n){
            int c=a+b;
            a=b%mod;
            b=c%mod;
            n--;
        }
        return b;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends