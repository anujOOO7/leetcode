//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        // code here
        long long sum=0,temp=N;
        for(long long i=0;i<K;i++){
            sum+=GeekNum[i];
        }
        
        GeekNum.push_back(sum);
        long long f=0,index=K;

        while(--temp){
            sum+=GeekNum[index];
            sum-=GeekNum[f];
            GeekNum.push_back(sum);
            f++;
            index++;
        }
        return GeekNum[N-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends