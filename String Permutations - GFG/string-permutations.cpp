//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<int> freq;
    vector<string> ans;
    void f(int i,vector<int>& freq,string temp,string s){
        if(temp.length()==s.length()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<s.length();i++){
            if(freq[i]==0){
                freq[i]=1;
                f(i+1,freq,temp+s[i],s);
                freq[i]=0;
            }
        }
    }
    vector<string> permutation(string S)
    {
        freq.resize(S.length()+1,0);
        f(0,freq,"",S);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends