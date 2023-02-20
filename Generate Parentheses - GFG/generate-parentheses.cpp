//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> v;
    
    void gen(int op,int cl,int n,string s){
        if(op+cl==2*n){
            v.push_back(s);
            return ;
        }
        
        //inserting opening bracket
        if(op+1<=n)
            gen(op+1,cl,n,s+'(');
            
        //inserting closing bracket
        if(cl+1<=n && op>=cl+1)
            gen(op,cl+1,n,s+')');
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        string ans="";
        gen(0,0,n,ans);
        return v;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends