//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int sieve[100005];
      void pre(){
          for(int i = 1;i<=100000;i++){
              sieve[i]=i;
          }
          sieve[0] = 0;
          sieve[1] = 1;
          
          for(int i = 2;i*i<=100000;i++){
              if(sieve[i]==i){
                  for(int j = i*i;j<=100000;j+=i){
                    if(sieve[j]==j){
                        sieve[j]=i;
                    }
                  }
              }
          }
      }
  public:
    vector<int> leastPrimeFactor(int n) {
        pre();
        vector<int>ans;
        // code here
       // ans.push_back(0);
        for(int i = 0;i<=n;i++){
            ans.push_back(sieve[i]);
        }
        return ans;
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
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends