//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int square_sum(int n) {
        int total = 0;
        while(n > 0) {
            int digit = n%10;
            total += (digit * digit);
            n /= 10;
        }
        return total;
    }
    
    bool isHappy(int n, unordered_set<int>& memo) {
        if(n == 1) return true;
        
        if(memo.count(n) > 0) return false;
        memo.insert(n);
        
        int next = square_sum(n);
        return isHappy(next, memo);
    }
    
    int nextHappy(int N){
        // code here
        int ans = 0;
        unordered_set<int> memo;
        for(int i=N+1; ; i++) {
            if(isHappy(i, memo)) return i;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends