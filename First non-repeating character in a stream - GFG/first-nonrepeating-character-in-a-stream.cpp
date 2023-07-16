//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	string FirstNonRepeating(string A){
	    // Code here
        vector<int> v(26,0);vector<int> cnt(26,0);
        string t;
        int ct=1;
         for(auto it:A){
             v[it-'a']++;
             cnt[it-'a']=ct++;
             char c='#';
             int res=INT_MAX;
             for(int i=0;i<26;i++){
                 if(v[i]==1){
                     if(res>cnt[i]){
                        c=(char)i+'a';
                        res=cnt[i];
                     }
                 }
             }
             t.push_back(c);
         }
         return t;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends