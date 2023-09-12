//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int sum){
        if(sum==0 && n>1 || sum>n*9) return "-1";
        string ans;
        for(int i=0;i<n;i++){
            int temp;
            if(sum>0){
                temp=min(9,sum);
                ans+=(temp+'0');
                sum-=temp;
            }
            else ans+='0';
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends