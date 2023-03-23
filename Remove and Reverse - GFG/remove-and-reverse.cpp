//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s)
    {
        string ans1,ans2;
        map<char,int>mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        int c=0,i=0,j=s.size()-1;
        while(i<=j)
        {
            if(c%2==0)
            {
                if(mp[s[i]]>1)
                {
                    mp[s[i]]--;
                    c++;
                }
                else
                    ans1+=s[i];
                i++;
            }
            else
            {
                if(mp[s[j]]>1)
                {
                    mp[s[j]]--;
                    c++;
                }
                else 
                ans2=s[j]+ans2;
                j--;
            }
        }
        ans1=ans1+ans2;
        if(c%2)
            reverse(ans1.begin(),ans1.end());
        return ans1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends