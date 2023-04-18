//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string s, int X){
        // code here
        string ans=s;
        for(int i=0;i<N;i++){
            if(s[i]=='1'){
                for(int j=1;j<=X && i+j<N;j++)
                    ans[i+j]='1';
            }
        }
        // cout<<ans<<endl;
        for(int i=N-1;i>=0;i--){
            if(s[i]=='1'){
                for(int j=1;j<=X && i-j>=0;j++)
                    ans[i-j]='1';
            }
        }
        // cout<<ans<<endl;
        for(int i=0;i<N;i++){
            if(ans[i]=='0') return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends