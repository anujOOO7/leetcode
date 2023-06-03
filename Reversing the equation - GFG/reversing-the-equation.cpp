//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
    {
        //code here.
        int i,count=0;
        for(i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9'){
                count++;
            }
            else{
                reverse(s.begin()+i-count,s.begin()+i);
                count=0;
            }
        }
        reverse(s.begin()+i-count,s.begin()+i);
        reverse(s.begin(),s.end());
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends