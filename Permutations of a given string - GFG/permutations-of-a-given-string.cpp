//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    set<string> ans;
	    void f(string s,string &temp,int cnt){
	        if(cnt==s.length()){
	            ans.insert(temp);
	            return;
	        }
	        
	        for(int j=0;j<s.length();j++){
	            if(s[j]!='1'){
	                temp.push_back(s[j]);
	                char aa=s[j];
	                s[j]='1';
	                f(s,temp,cnt+1);
	                s[j]=aa;
	                temp.pop_back();
	            }
	        }
	        return;
	    }
		vector<string>find_permutation(string S)
		{
		    int cnt=0;
		    string temp;
		    f(S,temp,cnt);
		    
		    vector<string> res;
		    for(auto i:ans) res.push_back(i);
		    return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends