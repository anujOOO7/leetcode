//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string s){
        // Code here
        string ans="";
        ans+=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]>s[i-1] && i!=1) break;
            if(s[i]>=s[i-1] && i==1) break;
            ans+=s[i];
        }
        string res=ans;
        reverse(begin(ans),end(ans));
        res+=ans;
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends